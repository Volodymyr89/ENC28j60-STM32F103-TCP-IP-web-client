#ifndef _ENC28J60_H
#define _ENC28J60_H

// if not defined enable pin throw error
#ifndef enableChip
	# Error! Please define PIN to enable ENC28J60!
#endif
// if not defined disable pin throw error
#ifndef disableChip
	# Error! Please define PIN to disable ENC28J60!
#endif
// if not defined mymacaddrthrow error
#ifndef disableChip
	# Error! Please define PIN to disable ENC28J60!
#endif
	
	
void enc28j60Init( uint8_t* macaddr );
void enc28j60Init( uint8_t* macaddr );	

#endif