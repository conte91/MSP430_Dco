#pragma once

#define CALDCO_1MHZ  (*((unsigned char*) 0x10C0))
#define CALBC1_1MHZ  (*((unsigned char*) 0x10C1))
#define CALDCO_2MHZ  (*((unsigned char*) 0x10C2))
#define CALBC1_2MHZ  (*((unsigned char*) 0x10C3))
#define CALDCO_3MHZ  (*((unsigned char*) 0x10C4))
#define CALBC1_3MHZ  (*((unsigned char*) 0x10C5))
#define CALDCO_4MHZ  (*((unsigned char*) 0x10C6))
#define CALBC1_4MHZ  (*((unsigned char*) 0x10C7))
#define CALDCO_5MHZ  (*((unsigned char*) 0x10C8))
#define CALBC1_5MHZ  (*((unsigned char*) 0x10C9))
#define CALDCO_6MHZ  (*((unsigned char*) 0x10CA))
#define CALBC1_6MHZ  (*((unsigned char*) 0x10CB))
#define CALDCO_7MHZ  (*((unsigned char*) 0x10CC))
#define CALBC1_7MHZ  (*((unsigned char*) 0x10CD))
#define CALDCO_8MHZ  (*((unsigned char*) 0x10CE))
#define CALBC1_8MHZ  (*((unsigned char*) 0x10CF))
#define CALDCO_9MHZ  (*((unsigned char*) 0x10D0))
#define CALBC1_9MHZ  (*((unsigned char*) 0x10D1))
#define CALDCO_10MHZ (*((unsigned char*) 0x10D2))
#define CALBC1_10MHZ (*((unsigned char*) 0x10D3))
#define CALDCO_11MHZ (*((unsigned char*) 0x10D4))
#define CALBC1_11MHZ (*((unsigned char*) 0x10D5))
#define CALDCO_12MHZ (*((unsigned char*) 0x10D6))
#define CALBC1_12MHZ (*((unsigned char*) 0x10D7))
#define CALDCO_13MHZ (*((unsigned char*) 0x10D8))
#define CALBC1_13MHZ (*((unsigned char*) 0x10D9))
#define CALDCO_14MHZ (*((unsigned char*) 0x10F0))
#define CALBC1_14MHZ (*((unsigned char*) 0x10F1))
#define CALDCO_15MHZ (*((unsigned char*) 0x10F2))
#define CALBC1_15MHZ (*((unsigned char*) 0x10F3))
#define CALDCO_16MHZ (*((unsigned char*) 0x10F4))
#define CALBC1_16MHZ (*((unsigned char*) 0x10F5))

enum _DCOclock{
    DCO_1MHZ,
    DCO_2MHZ,
    DCO_3MHZ,
    DCO_4MHZ,
    DCO_5MHZ,
    DCO_6MHZ,
    DCO_7MHZ,
    DCO_8MHZ,
    DCO_9MHZ,
    DCO_10MHZ,
    DCO_11MHZ,
    DCO_12MHZ,
    DCO_13MHZ,
    DCO_14MHZ,
    DCO_15MHZ,
    DCO_16MHZ
    };

typedef enum _DCOclock DCOclock;

void Setup_DCO(DCOclock which);
