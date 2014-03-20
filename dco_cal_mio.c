// Calibrate DCO and
// save the costants into flash seg. A preserving compatibility
// with previous constants being written during factory calibration.
// Michele Porelli & Massimo Pennazio
// License creative commons

#include <msp430g2553.h>
#include "DCO_Library.h"

#define FLASH_A_START		        0x10c0
#define FLASH_A_END			        0x10FF
#define TAG_DCO_CUSTOM_P1_START     0x10C0
#define TAG_DCO_CUSTOM_P2_START     0x10F0
#define TAG_DCO_CUSTOM_DELTA        22

#define SIZE				(64)			// 64 bytes

// prototipi funzioni
void Setup_uC(void);
void Set_DCO(unsigned int);
void erase_segment_A(void);
void write_segment_A(void);
void flash_segA_backup();
void cal_DCO_BC1(unsigned int,unsigned char);
unsigned char chk_data();
void toggle_red_led();
void spettacolino();

// variabili globali
unsigned char segment_A[SIZE];               // Temp. storage for constants


void main(void)
{
    unsigned int i,j;

    WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT

    Setup_uC();

	for(i=0;i<10;i++)
	{
    	for (j= 0;j<0xfffe;j++);           // Ritardo per permettere al quarzo esterno di partire
	}
    
    while(BCSCTL3 & LFXT1OF)                  // se il quarzo esterno ha problemi (danneggiato/mancante) segnalalo
    {
        P1OUT |= BIT0;                        // accendi il led rosso
    }
    P1OUT &=~ (BIT0 + BIT6);                   // spengo tutti e due i led


    flash_segA_backup();


    for(i=0; i<32; i+=2)
    {
        switch(i)
        {

        case 0:
            cal_DCO_BC1(TI_DCO_1MHZ,i);
            break;
        case 2:
            cal_DCO_BC1(TI_DCO_2MHZ,i);
            break;
        case 4:
            cal_DCO_BC1(TI_DCO_3MHZ,i);
            break;
        case 6:
            cal_DCO_BC1(TI_DCO_4MHZ,i);
            break;
        case 8:
            cal_DCO_BC1(TI_DCO_5MHZ,i);
            break;
        case 10:
            cal_DCO_BC1(TI_DCO_6MHZ,i);
            break;
        case 12:
            cal_DCO_BC1(TI_DCO_7MHZ,i);
            break;
        case 14:
            cal_DCO_BC1(TI_DCO_8MHZ,i);
            break;
        case 16:
            cal_DCO_BC1(TI_DCO_9MHZ,i);
            break;
        case 18:       	
            cal_DCO_BC1(TI_DCO_10MHZ,i);
            break;
        case 20:
            cal_DCO_BC1(TI_DCO_11MHZ,i);
            break;
        case 22:
            cal_DCO_BC1(TI_DCO_12MHZ,i);
            break;
        case 24:
            cal_DCO_BC1(TI_DCO_13MHZ,i);
            break;
        case 26:
            cal_DCO_BC1(TI_DCO_14MHZ,i+TAG_DCO_CUSTOM_DELTA);
            break;
        case 28:
            cal_DCO_BC1(TI_DCO_15MHZ,i+TAG_DCO_CUSTOM_DELTA);
            break;
        case 30:
            cal_DCO_BC1(TI_DCO_16MHZ,i+TAG_DCO_CUSTOM_DELTA);
            break;
        }
        toggle_red_led();
    }
	Set_DCO(TI_DCO_1MHZ);			// slow down clock for flash writing
    erase_segment_A();
    write_segment_A();

    if(chk_data()==0)
    {
        P1OUT = 0;
        while (1)
        {
            spettacolino();
        }
    }
    else
    {
        P1OUT |= BIT0;                         // bring P1.0 high (Launchpad red LED)
        while(1);
    }
}// end main


void Set_DCO(unsigned int Delta)            // Set DCO to selected frequency
{
  unsigned int Compare, Oldcapture = 0;

  BCSCTL1 |= DIVA_3;                        // ACLK = LFXT1CLK/8
  TACCTL0 = CM_1 + CCIS_1 + CAP;            // CAP, ACLK
  TACTL = TASSEL_2 + MC_2 + TACLR;          // SMCLK, cont-mode, clear

  while (1)
  {
    while (!(CCIFG & TACCTL0));             // Wait until capture occured
    TACCTL0 &= ~CCIFG;                      // Capture occured, clear flag
    Compare = TACCR0;                       // Get current captured SMCLK
    Compare = Compare - Oldcapture;         // SMCLK difference
    Oldcapture = TACCR0;                    // Save current captured SMCLK

    if (Delta == Compare)
      break;                                // If equal, leave "while(1)"
    else if (Delta < Compare)
    {
      DCOCTL--;                             // DCO is too fast, slow it down
      if (DCOCTL == 0xFF)                   // Did DCO roll under?
        if (BCSCTL1 & 0x0f)
          BCSCTL1--;                        // Select lower RSEL
    }
    else
    {
      DCOCTL++;                             // DCO is too slow, speed it up
      if (DCOCTL == 0x00)                   // Did DCO roll over?
        if ((BCSCTL1 & 0x0f) != 0x0f)
          BCSCTL1++;                        // Sel higher RSEL
    }
  }
  TACCTL0 = 0;                              // Stop TACCR0
  TACTL = 0;                                // Stop Timer_A
  BCSCTL1 &= ~DIVA_3;                       // ACLK = LFXT1CLK
}

void erase_segment_A(void)
{
    unsigned char *Flash_ptrA = (unsigned char *)FLASH_A_START;       // Point to beginning of seg A

    FCTL2 = FWKEY + FSSEL0 + FN1;             // MCLK/3 for Flash Timing Generator
    FCTL1 = FWKEY + ERASE;                    // Set Erase bit
    FCTL3 = FWKEY + LOCKA;                    // Clear LOCK & LOCKA bits
    *Flash_ptrA = 0x00;                       // Dummy write to erase Flash seg A
    FCTL1 = FWKEY;                            // Clear WRT bit
    FCTL3 = FWKEY + LOCKA + LOCK;             // Set LOCK & LOCKA bit

}
void write_segment_A(void)
{
    unsigned char j;
    unsigned char *Flash_ptrA = (unsigned char *)FLASH_A_START; 	      // Point to beginning of flash seg. A

    FCTL2 = FWKEY + FSSEL0 + FN1;           // MCLK/3 for Flash Timing Generator
    FCTL1 = FWKEY + WRT;                    // Set WRT bit for write operation
    FCTL3 = FWKEY + LOCKA;                    // Clear LOCK & LOCKA bits

    for (j = 0; j < SIZE; j++)
    {
        *Flash_ptrA = segment_A[j];            // re-flash DCO calibration data
        Flash_ptrA++;
    }
    FCTL1 = FWKEY;                            	// Clear WRT bit
    FCTL3 = FWKEY + LOCKA + LOCK;             	// Set LOCK & LOCKA bit
}
unsigned char chk_data(void)
{

    unsigned char i,count=0;
    unsigned char *Flash_ptrA = (unsigned char *)FLASH_A_START;

    for(i=0;i<SIZE;i++)
    {
        if(*Flash_ptrA != segment_A[i])
        {
            count++;
        }
		*Flash_ptrA++;
    }
    if(count == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

void Setup_uC()
{

    // SMCLK config
    BCSCTL2 = DIVS_0;                    			// SMCLK source its freq from MCLK/1
    
    // port 1 configuration
    P1DIR = 0xFF;                            // P1 output
    P1OUT = 0x00;

    // port 2 configuration
    P2DIR = 0xFF;
    P2OUT = 0x00;
    P2DIR &= ~(BIT6 + BIT7);					// xin xout proper configuration for external quartz
    P2REN &= ~(BIT6 + BIT7);					// disable pull-up resistors for external quartz
    P2SEL |= (BIT6 + BIT7);
    P2SEL2 &= ~(BIT6 + BIT7);

	// configurazione clock esterno 32768Hz
    BCSCTL1 &= ~XTS;                        		// external source is LF;
    BCSCTL3 &= ~(LFXT1S0 + LFXT1S1);              	// watch crystal mode
    BCSCTL3 = XCAP_3; 								//capacità  sul quarzo esterno 12.5pF
	BCSCTL1 |= DIVA_0; 								//ACLK/1
}

void flash_segA_backup()
{
    unsigned char i;
    unsigned char *Flash_ptrA = (unsigned char *)FLASH_A_START;  // Point to beginning of segment A

    for(i=0; i<SIZE; i++)
    {
        segment_A[i] = *Flash_ptrA++;
    }
}

void cal_DCO_BC1(unsigned int delta,unsigned char i)
{

    Set_DCO(delta);
    segment_A[i] = DCOCTL;
    segment_A[i+1] = BCSCTL1;

}

void toggle_red_led()
{
	unsigned int i;
	
	P1OUT |= BIT0;
	for (i = 0; i < 0xfffe; i++);
	P1OUT &= ~BIT0;
}

void spettacolino()							// fa lampeggiare il led verde per indicare successo
{
	unsigned int i,j;
	
	P1OUT ^= BIT6;                          // Toggle green LED
    for(i=0;i<5;i++)
    {
    	for (j = 0; j < 16384; j++);           // SW Delay
    }	
}

	

