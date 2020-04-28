#include <iostream>
using namespace std;
int main()
{
	int input_var;
	int kRand=rand() % 100+1;
	cout << kRand << endl;
	while(true)
	{
		cout << "Type in the no:";
		cin >> input_var;
		if(input_var<kRand)
			cout << "Too low" << endl;
		else if (input_var>kRand)
		{
			cout << "Too high" << endl;
		}
		else
		{
			cout << "Correct" << endl;
			break;
		}
	}
	
	return 0;
}