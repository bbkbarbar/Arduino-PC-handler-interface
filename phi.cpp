// FILE: phi.h
// VERSION: 0.4.1
//

#include "phi.h"

void phi::setup() {
	//mode: INPUT, OUTPUT, or INPUT_PULLUP.
	pinMode(PIN_RESET_BUTTON, OUTPUT);
	pinMode(PIN_POWER_BUTTON, OUTPUT);
	pinMode(PIN_RELAY_1, OUTPUT);
	pinMode(PIN_RELAY_2, OUTPUT);
}

void phi::pressReset(long pressing_time_in_ms){
	digitalWrite(PIN_RESET_BUTTON, HIGH);
	delay(pressing_time_in_ms);
	digitalWrite(PIN_RESET_BUTTON, LOW);
}

void phi::pressReset(){
	pressReset(DEFAULT_BUTTON_SHORT_PRESS_TIME_IN_MS);
}
