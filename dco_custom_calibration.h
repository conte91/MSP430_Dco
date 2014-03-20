// Custom calibration of msp430's DCO
// include this file in your project after
// flash costants calibration with dco_cal project http://
// Michele Porelli & Massimo Pennazio 2012
// Creative commons license
//
#ifndef DCO_CUSTOM_CALIBRATION_H_
	#define DCO_CUSTOM_CALIBRATION_H_

	#ifndef __DisableCalData
		#define __DisableCalData		// directive used to disable factory calibration
			#ifdef CALDCO_16MHZ
				#undef CALDCO_16MHZ
			#endif
			#ifdef CALBC1_16MHZ
				#undef CALBC1_16MHZ
			#endif
			#ifdef CALDCO_12MHZ
				#undef CALDCO_12MHZ
			#endif
			#ifdef CALBC1_12MHZ
				#undef CALBC1_12MHZ
			#endif
			#ifdef CALDCO_8MHZ
				#undef CALDCO_8MHZ
			#endif
			#ifdef CALBC1_8MHZ
				#undef CALBC1_8MHZ
			#endif
			#ifdef CALDCO_1MHZ
				#undef CALDCO_1MHZ
			#endif
			#ifdef CALBC1_1MHZ
				#undef CALBC1_1MHZ
			#endif
			
		#define __CustomCalData			// instead use ad hoc calibrated frequecies
		
		SFR_8BIT(CALDCO_16MHZ);                       /* DCOCTL  Calibration Data for 16MHz */
		SFR_8BIT(CALBC1_16MHZ);                       /* BCSCTL1 Calibration Data for 16MHz */
		SFR_8BIT(CALDCO_15MHZ);                       /* DCOCTL  Calibration Data for 15MHz */
		SFR_8BIT(CALBC1_15MHZ);                       /* BCSCTL1 Calibration Data for 15MHz */
		SFR_8BIT(CALDCO_14MHZ);                        /* DCOCTL  Calibration Data for 14MHz */
		SFR_8BIT(CALBC1_14MHZ);                        /* BCSCTL1 Calibration Data for 14MHz */
		SFR_8BIT(CALDCO_13MHZ);                        /* DCOCTL  Calibration Data for 13MHz */
		SFR_8BIT(CALBC1_13MHZ);                        /* BCSCTL1 Calibration Data for 13MHz */
		SFR_8BIT(CALDCO_12MHZ);                       /* DCOCTL  Calibration Data for 12MHz */
		SFR_8BIT(CALBC1_12MHZ);                       /* BCSCTL1 Calibration Data for 12MHz */
		SFR_8BIT(CALDCO_11MHZ);                       /* DCOCTL  Calibration Data for 11MHz */
		SFR_8BIT(CALBC1_11MHZ);                       /* BCSCTL1 Calibration Data for 11MHz */
		SFR_8BIT(CALDCO_10MHZ);                        /* DCOCTL  Calibration Data for 10MHz */
		SFR_8BIT(CALBC1_10MHZ);                        /* BCSCTL1 Calibration Data for 10MHz */
		SFR_8BIT(CALDCO_9MHZ);                        /* DCOCTL  Calibration Data for 9MHz */
		SFR_8BIT(CALBC1_9MHZ);                        /* BCSCTL1 Calibration Data for 9MHz */
		SFR_8BIT(CALDCO_8MHZ);                       /* DCOCTL  Calibration Data for 8MHz */
		SFR_8BIT(CALBC1_8MHZ);                       /* BCSCTL1 Calibration Data for 8MHz */
		SFR_8BIT(CALDCO_7MHZ);                       /* DCOCTL  Calibration Data for 7MHz */
		SFR_8BIT(CALBC1_7MHZ);                       /* BCSCTL1 Calibration Data for 7MHz */
		SFR_8BIT(CALDCO_6MHZ);                        /* DCOCTL  Calibration Data for 6MHz */
		SFR_8BIT(CALBC1_6MHZ);                        /* BCSCTL1 Calibration Data for 6MHz */
		SFR_8BIT(CALDCO_5MHZ);                        /* DCOCTL  Calibration Data for 5MHz */
		SFR_8BIT(CALBC1_5MHZ);                        /* BCSCTL1 Calibration Data for 5MHz */
		SFR_8BIT(CALDCO_4MHZ);                       /* DCOCTL  Calibration Data for 4MHz */
		SFR_8BIT(CALBC1_4MHZ);                       /* BCSCTL1 Calibration Data for 4MHz */
		SFR_8BIT(CALDCO_3MHZ);                       /* DCOCTL  Calibration Data for 3MHz */
		SFR_8BIT(CALBC1_3MHZ);                       /* BCSCTL1 Calibration Data for 3MHz */
		SFR_8BIT(CALDCO_2MHZ);                        /* DCOCTL  Calibration Data for 2MHz */
		SFR_8BIT(CALBC1_2MHZ);                        /* BCSCTL1 Calibration Data for 2MHz */
		SFR_8BIT(CALDCO_1MHZ);                        /* DCOCTL  Calibration Data for 1MHz */
		SFR_8BIT(CALBC1_1MHZ);                        /* BCSCTL1 Calibration Data for 1MHz */

	#endif
#endif /*DCO_CUSTOM_CALIBRATION_H_*/
