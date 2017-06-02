// FILE: phi.h
// VERSION: 0.4.1
//

#ifndef phi_h
#define phi_h
//#include "phi.cpp"

#if defined(ARDUINO) && (ARDUINO >= 100)
	#include <Arduino.h>
#else
	#include <WProgram.h>
#endif

#define PC_HANDLER_INTERFACE_LIB_VERSION    "0.0.1"





class PHI {

	#define AC_STATE_ON                              0
	#define AC_STATE_OFF                             1

	#define PIN_RESET_BUTTON                         4
	#define PIN_POWER_BUTTON                         5
	#define PIN_RELAY_1                              6
	#define PIN_RELAY_2                              7

	#define DEFAULT_BUTTON_SHORT_PRESS_TIME_IN_MS  500
	#define DEFAULT_BUTTON_LONG_PRESS_TIME_IN_MS  6500
	
	public:
		void init();
	    void pressReset();
	    void pressReset(long pressing_time_in_ms);
	    void pressPower();
	    void pressPower(long pressing_time_in_ms);

	    char turnAC(char newState);

		int temperature;

};


char PHI::turnAC(char newState){
	char previousState1 = digitalRead(PIN_RELAY_1);
	char previousState2 = digitalRead(PIN_RELAY_2);

	digitalWrite(PIN_RELAY_1, newState);
	digitalWrite(PIN_RELAY_2, newState);

	if(previousState1 != previousState2){
		return 3;
	}
	return previousState1;
}


void PHI::init() {
	//mode: INPUT, OUTPUT, or INPUT_PULLUP.
	pinMode(PIN_RESET_BUTTON, OUTPUT);
	pinMode(PIN_POWER_BUTTON, OUTPUT);
	pinMode(PIN_RELAY_1, OUTPUT);
	pinMode(PIN_RELAY_2, OUTPUT);
}



void PHI::pressReset(long pressing_time_in_ms){
	digitalWrite(PIN_RESET_BUTTON, HIGH);
	delay(pressing_time_in_ms);
	digitalWrite(PIN_RESET_BUTTON, LOW);
}

void PHI::pressReset(){
	pressReset(DEFAULT_BUTTON_SHORT_PRESS_TIME_IN_MS);
}



void PHI::pressPower(long pressing_time_in_ms){
	digitalWrite(PIN_POWER_BUTTON, HIGH);
	delay(pressing_time_in_ms);
	digitalWrite(PIN_POWER_BUTTON, LOW);
}

void PHI::pressPower(){
	pressReset(DEFAULT_BUTTON_SHORT_PRESS_TIME_IN_MS);
}



#endif