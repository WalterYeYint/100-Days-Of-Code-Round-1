#include <iostream>
using namespace std;

int main()
{
	int input_var1 , input_var2 = 0;
	do{
		cout << "Enter two numbers (-1 = quit): ";
		if(!(cin >> input_var1 >> input_var2)){
			cout << "Please enter numbers only." << endl;
			cin.clear();
			cin.ignore(10000,'\n');
		}
		if((input_var1 != -1) || (input_var2 != -1)){
			cout << "You entered " << input_var1 << "&" << input_var2 << endl;
		}
	}
	while ((input_var1 != -1) || (input_var2 != -1));
  	cout << "All done." << endl;
	return 0;
}

void gcd(int x,int y){
	
}