/*
	Morse.h - Library for flashing Morse rewritten by Kan Yu
	Created by David A. Mellis

	Kan Yu just trying to warming up again
*/

#ifndef Morse_h
#define Morse_h

class Morse
{
	public:
		int publicvar;
		Morse(int pin);
		void dot();
		void dash();
		int show();
	private:
		int _pin;
};
#endif