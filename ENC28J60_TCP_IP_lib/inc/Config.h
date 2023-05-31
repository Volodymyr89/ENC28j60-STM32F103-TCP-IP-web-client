#ifndef _CONFIHG_H
#define _CONFIHG_H

#include <stdint.h>

// define PINs to enble/disable ENC28J60 chip
#define enableChip
#define disableChip

// set ENC28J60 macaddr
uint8_t mymacaddr[6]={0,0,0,0,0,0};
uint8_t myip[4]={0,0,0,0};

#endif