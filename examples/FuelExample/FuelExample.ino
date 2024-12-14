#include <FuelController.h>


int FUEL_PIN = 5;  // Pin 5
/** 
  PWM de 0 a 30
*/
int FUEL_PWM_MAX = 30;
int FUEL_PWM_MIN = 0;

// INITIAL VALUE TO FUEL THAT ONE IS EMPTY. 100 EMPTY AND 0 FULL
int FUEL_INITIAL_STATE = 100;
JsonDeserializeAlp jsonDeserialize;
FuelObject fuel(FUEL_PIN, FUEL_PWM_MIN, FUEL_PWM_MAX, FUEL_INITIAL_STATE);

FuelController fuelControl(fuel);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("init program");
  // Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    String json = Serial.readStringUntil('\n');

    fuelControl.update(json);
  }
}
