#include <msp430.h>
#include "dco_custom_calibration.h"

unsigned long DCOFrequency=1000000;

void Setup_DCO(DCOclock which){

  switch(which){
    case DCO_1MHZ:
      if (CALBC1_1MHZ ==0xFF || CALDCO_1MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_1MHZ;
      BCSCTL1=CALBC1_1MHZ;
      break;
    case DCO_2MHZ:
      if (CALBC1_2MHZ ==0xFF || CALDCO_2MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_2MHZ;
      BCSCTL1=CALBC1_2MHZ;
      break;
    case DCO_3MHZ:
      if (CALBC1_3MHZ ==0xFF || CALDCO_3MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_3MHZ;
      BCSCTL1=CALBC1_3MHZ;
      break;
    case DCO_4MHZ:
      if (CALBC1_4MHZ ==0xFF || CALDCO_4MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_4MHZ;
      BCSCTL1=CALBC1_4MHZ;
      break;
    case DCO_5MHZ:
      if (CALBC1_5MHZ ==0xFF || CALDCO_5MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_5MHZ;
      BCSCTL1=CALBC1_5MHZ;
      break;
    case DCO_6MHZ:
      if (CALBC1_6MHZ ==0xFF || CALDCO_6MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_6MHZ;
      BCSCTL1=CALBC1_6MHZ;
      break;
    case DCO_7MHZ:
      if (CALBC1_7MHZ ==0xFF || CALDCO_7MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_7MHZ;
      BCSCTL1=CALBC1_7MHZ;
      break;
    case DCO_8MHZ:
      if (CALBC1_8MHZ ==0xFF || CALDCO_8MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_8MHZ;
      BCSCTL1=CALBC1_8MHZ;
      break;
    case DCO_9MHZ:
      if (CALBC1_9MHZ ==0xFF || CALDCO_9MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_9MHZ;
      BCSCTL1=CALBC1_9MHZ;
      break;
    case DCO_10MHZ:
      if (CALBC1_10MHZ ==0xFF || CALDCO_10MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_10MHZ;
      BCSCTL1=CALBC1_10MHZ;
      break;
    case DCO_11MHZ:
      if (CALBC1_11MHZ ==0xFF || CALDCO_11MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_11MHZ;
      BCSCTL1=CALBC1_11MHZ;
      break;
    case DCO_12MHZ:
      if (CALBC1_12MHZ ==0xFF || CALDCO_12MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_12MHZ;
      BCSCTL1=CALBC1_12MHZ;
      break;
    case DCO_13MHZ:
      if (CALBC1_13MHZ ==0xFF || CALDCO_13MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_13MHZ;
      BCSCTL1=CALBC1_13MHZ;
      break;
    case DCO_14MHZ:
      if (CALBC1_14MHZ ==0xFF || CALDCO_14MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_14MHZ;
      BCSCTL1=CALBC1_14MHZ;
      break;
    case DCO_15MHZ:
      if (CALBC1_15MHZ ==0xFF || CALDCO_15MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_15MHZ;
      BCSCTL1=CALBC1_15MHZ;
      break;
    case DCO_16MHZ:
      if (CALBC1_16MHZ ==0xFF || CALDCO_16MHZ == 0xFF) 	// If calibration constants erased                                     
  		{
  			while(1);                   				// do not load, trap CPU!
  		}
      DCOCTL=CALDCO_16MHZ;
      BCSCTL1=CALBC1_16MHZ;
      break;
  }
}
