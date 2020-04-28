/*
	Morse.cpp - Library for flashing Morse rewritten by Kan
	Created by David A. Mellis, November 2, 2007.
	Kan Yu just warming up again
*/

#include "Arduino.h"
#include "Morse.h"

Morse::Morse(int pin){
	pinMode(pin,OUTPUT);
	_pin=pin;
	publicvar=pin;
}

void Morse::dot(){
	digitalWrite(_pin,HIGH);
	delay(250);
	digitalWrite(_pin,LOW);
	delay(250);
}

void Morse::dash(){
  digitalWrite(_pin, HIGH);
  delay(1000);
  digitalWrite(_pin, LOW);
  delay(250);
}

int Morse::show(){
	return publicvar;
}