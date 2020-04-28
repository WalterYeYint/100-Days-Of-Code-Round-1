/*
	cannonbolt.h - Library for calculating connonball trajectory
	Created by Google Edu (written into library by Kan Yu) , 25.5.2019

	Changed the code so that inputs can be entered by user
*/

#ifndef CANNONBOLT_H
#define CANNONBOLT_H

class cannonbolt{
	public:
		cannonbolt();
		int Fire(int number_killed);
		int Initialize();
		int CheckShot();
		int DistanceCalc (double in_angle);
		virtual ~cannonbolt();
};
#endif
