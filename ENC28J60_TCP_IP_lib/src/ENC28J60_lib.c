#include <stdint.h>
#include "Config.h"
#include "ENC28J60_lib.h"


void enc28j60Init( uint8_t* macaddr )
{
	ENABLECHIP; // ss=0

	// perform system reset
	enc28j60WriteOp(ENC28J60_SOFT_RESET, 0, ENC28J60_SOFT_RESET);
	HAL_Delay(50);
	// check CLKRDY bit to see if reset is complete
        // The CLKRDY does not work. See Rev. B4 Silicon Errata point. Just wait.
	//while(!(enc28j60Read(ESTAT) & ESTAT_CLKRDY));
	// do bank 0 stuff
	// initialize receive buffer
	// 16-bit transfers, must write low byte first
	// set receive buffer start address
	gNextPacketPtr = RXSTART_INIT;
        // Rx start
	enc28j60WriteWord(ERXSTL, RXSTART_INIT);
	// set receive pointer address
	enc28j60WriteWord(ERXRDPTL, RXSTART_INIT);
	// RX end
	enc28j60WriteWord(ERXNDL, RXSTOP_INIT);
	// TX start
	enc28j60WriteWord(ETXSTL, TXSTART_INIT);
	// TX end
	enc28j60WriteWord(ETXNDL, TXSTOP_INIT);
	// do bank 1 stuff, packet filter:
        // For broadcast packets we allow only ARP packtets
        // All other packets should be unicast only for our mac (MAADR)
        //
        // The pattern to match on is therefore
        // Type     ETH.DST
        // ARP      BROADCAST
        // 06 08 -- ff ff ff ff ff ff -> ip checksum for theses bytes=f7f9
        // in binary these poitions are:11 0000 0011 1111
        // This is hex 303F->EPMM0=0x3f,EPMM1=0x30
 
	//enc28j60Write(ERXFCON, ERXFCON_UCEN|ERXFCON_CRCEN|ERXFCON_PMEN);
        //Change to add ERXFCON_BCEN recommended by epam
	//enc28j60Write(ERXFCON, ERXFCON_UCEN|ERXFCON_CRCEN|ERXFCON_PMEN|ERXFCON_BCEN);
        erxfcon =  ERXFCON_UCEN|ERXFCON_CRCEN|ERXFCON_PMEN|ERXFCON_BCEN;
	enc28j60Write(ERXFCON, erxfcon );
	enc28j60WriteWord(EPMM0, 0x303f);
	enc28j60WriteWord(EPMCSL, 0xf7f9);
        //
	// do bank 2 stuff
	// enable MAC receive
	enc28j60Write(MACON1, MACON1_MARXEN|MACON1_TXPAUS|MACON1_RXPAUS);
	// bring MAC out of reset
	enc28j60Write(MACON2, 0x00);
	// enable automatic padding to 60bytes and CRC operations
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, MACON3, MACON3_PADCFG0|MACON3_TXCRCEN|MACON3_FRMLNEN);  //|MACON3_FULDPX);
	// set inter-frame gap (non-back-to-back)
	enc28j60WriteWord(MAIPGL, 0x0C12);
	// set inter-frame gap (back-to-back)
	enc28j60Write(MABBIPG, 0x12);
	// Set the maximum packet size which the controller will accept
        // Do not send packets longer than MAX_FRAMELEN:
	enc28j60WriteWord(MAMXFLL, MAX_FRAMELEN);	
	// do bank 3 stuff
        // write MAC address
        // NOTE: MAC address in ENC28J60 is byte-backward
        enc28j60Write(MAADR5, macaddr[0]);
        enc28j60Write(MAADR4, macaddr[1]);
        enc28j60Write(MAADR3, macaddr[2]);
        enc28j60Write(MAADR2, macaddr[3]);
        enc28j60Write(MAADR1, macaddr[4]);
        enc28j60Write(MAADR0, macaddr[5]);
	// no loopback of transmitted frames
	enc28j60PhyWrite(PHCON2, PHCON2_HDLDIS);
	// switch to bank 0
	enc28j60SetBank(ECON1);
	// enable interrutps
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, EIE, EIE_INTIE|EIE_PKTIE);
	// enable packet reception
	enc28j60WriteOp(ENC28J60_BIT_FIELD_SET, ECON1, ECON1_RXEN);
}
void enc28j60Init( uint8_t* macaddr ) {
	
  /*initialize enc28j60*/
  enc28j60Init( macaddr );
  enc28j60clkout(2); // change clkout from 6.25MHz to 12.5MHz
  HAL_Delay(10);

  for( uint8_t f=0; f<3; f++ ) {
  	// 0x880 is PHLCON LEDB=on, LEDA=on
  	// enc28j60PhyWrite(PHLCON,0b0011 1000 1000 00 00);
  	enc28j60PhyWrite(PHLCON,0x3880);
  	HAL_Delay(500);

  	// 0x990 is PHLCON LEDB=off, LEDA=off
  	// enc28j60PhyWrite(PHLCON,0b0011 1001 1001 00 00);
  	enc28j60PhyWrite(PHLCON,0x3990);
  	HAL_Delay(500);
  }

  // 0x476 is PHLCON LEDA=links status, LEDB=receive/transmit
  // enc28j60PhyWrite(PHLCON,0b0011 0100 0111 01 10);
	enc28j60PhyWrite(PHLCON,0x3476);
	HAL_Delay(100);
}
uint8_t enc28j60ReadOp(uint8_t op, uint8_t address)
{
		uint8_t temp;
        enableChip;
        // issue read command
        ENC28J60_SendByte(op | (address & ADDR_MASK));
        temp = ENC28J60_SendByte(0xFF);
        if (address & 0x80)
            temp = ENC28J60_SendByte(0xFF);

        // release CS
        disableChip;
        return temp;
}
// read Opcode
uint8_t enc28j60ReadOp(uint8_t op, uint8_t address)
{
		uint8_t temp;
        enableChip;
        // issue read command
        ENC28J60_SendByte(op | (address & ADDR_MASK));
        temp = ENC28J60_SendByte(0xFF);
        if (address & 0x80)
            temp = ENC28J60_SendByte(0xFF);

        // release CS
        disableChip;
       
}
// write op code
void enc28j60WriteOp(uint8_t op, uint8_t address, uint8_t data)
{
    enableChip;
    ENC28J60_SendByte(op | (address & ADDR_MASK));
    ENC28J60_SendByte(data);
    disableChip;
}
// read from ENC
uint8_t enc28j60Read(uint8_t address)
{
        // set the bank
        enc28j60SetBank(address);
        // do the read
        return enc28j60ReadOp(ENC28J60_READ_CTRL_REG, address);
}



//write word
void enc28j60WriteWord(uint8_t address, uint16_t data) {
    enc28j60Write(address, data & 0xff);
    enc28j60Write(address + 1, data >> 8);
}

// read the revision of the chip:
uint8_t enc28j60getrev(void)
{
        uint8_t rev;
        rev=enc28j60Read(EREVID);
        // microchip forgot to step the number on the silcon when they
        // released the revision B7. 6 is now rev B7. We still have
        // to see what they do when they release B8. At the moment
        // there is no B8 out yet
        if (rev>5) rev++;
	return(rev);
}