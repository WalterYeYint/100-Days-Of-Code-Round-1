#include <iostream>
using namespace std;

void accelerate(float &sp , float amnt){
	sp = sp + amnt;
}

int main(){

	/*Actually you don't need this
	float *speed = new float();
	*/
	
	float amount = 30.5;
	float speed = 0;
	cout << "Enter speed" << endl;
	cin >> speed;
	accelerate(speed , amount);
	cout << "The new speed is " << speed <<endl;
	return 0;
}
