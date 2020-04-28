//Simple Fibonacci program
//Written by Kan Yu (Reference from Internet)
//Description:This program will output the Fibonacci number list till limit defined


#include <iostream>
using namespace std;

int main(){
    int x,y,z;
    while(1){
        x = 0;
        y = 1;
        do{
            cout << x << endl;
            z = x + y;
            x = y;
            y = z;
        }while(x < 255);
    }
    return 0 ;
}
