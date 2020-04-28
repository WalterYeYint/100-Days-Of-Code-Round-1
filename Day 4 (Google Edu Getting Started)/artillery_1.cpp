//Artillery.cpp (my own version)
//Rewritten by Kan Yu
//Kan Yu just loafing around

#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

double Velocity = 200.0; // initial velocity of 200 ft/sec
double Gravity = 32.2; // gravity for distance calculation
double in_angle,time_in_air = 0;
int kDistance,kShots,kKilled,killed = 0;
int kPos = rand() % 600 + 1;



void StartUp(){
	cout << "Welcome to Artillery." << endl;
	cout << "You are in the middle of a war and being charged by thousands of enemies." << endl;
	cout << "You have one cannon, which you can shoot at any angle." << endl;
	cout << "You only have 10 cannonballs for this target.." << endl;
	cout << "Let's begin..." << endl << endl << endl;

	cout << "The enemy is " << kPos << " feet away!!!" << endl;
}

int Fire(){
	double offset;
	do{
		cout << "What angle?" << endl;
		cin >> in_angle;
		// in_angle is the angle the player has entered, converted to radians.
		time_in_air = (2.0 * Velocity * sin(in_angle)) / Gravity;
		kDistance = round((Velocity * cos(in_angle)) * time_in_air);
		if(kDistance < kPos){
			offset = kPos - kDistance;
			cout << "You under shot by " << offset << endl;
		}
		else if (kDistance>kPos)
		{
			offset = kPos - kDistance;
			cout << "You over shot by " << offset << endl;
		}
	}while(kDistance != kPos);
	kKilled = kKilled + 1;
	cout << "You hit him!!!" << endl;
	cout << "It took you " << kShots << " shots." << endl;
	cout << "You have killed " << kKilled << " enemies." << endl;
	return kKilled;
}

int main(){
	char done;
	StartUp(); // This displays the introductory script.
	killed = 0;
	do {
		killed = Fire(); // Fire() contains the main loop of each round.
		cout << "I see another one, care to shoot again? (Y/N) " << endl;
	  cin >> done;
	} while (done != 'n');
	cout << "You killed " << killed << " of the enemy." << endl;
}
