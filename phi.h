// FILE: phi.h
// VERSION: 0.4.1
//

#ifndef phi_h
#define phi_h

#if defined(ARDUINO) && (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

#define PC_HANDLER_INTERFACE_LIB_VERSION    "0.0.1"


#ifndef PIN_RESET_BUTTON
	#define PIN_RESET_BUTTON		             4
#endif

#ifndef PIN_RESET_BUTTON
	#define PIN_POWER_BUTTON		             5
#endif

#ifndef PIN_RESET_BUTTON
	#define PIN_RELAY_1		                     6
#endif
#ifndef PIN_RESET_BUTTON
	#define PIN_RELAY_2		                     7
#endif


#define DEFAULT_BUTTON_SHORT_PRESS_TIME_IN_MS  500
#define DEFAULT_BUTTON_LONG_PRESS_TIME_IN_MS  6500


class phi {
	public:
		void setup();
	    void pressReset();
	    void pressReset(long pressing_time_in_ms);
	    void pressPower();
	    void pressPower(long pressing_time_in_ms);

		int temperature;

};

#endif