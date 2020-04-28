#include <Wire.h>
#include <Time.h>
#include <DS1307RTC.h>

void setup(){
    Serial.begin(9600);
    while (!Serial);
    delay(200);
    Serial.println("DS1307RTC Read Test");
    Serial.println("-------------------");
}

void loop(){
    tmElements
}