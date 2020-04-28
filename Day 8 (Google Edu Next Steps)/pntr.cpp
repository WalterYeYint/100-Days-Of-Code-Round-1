//Notice in this example that we never allocated memory with 
//the "new" operator. We declared a normal integer variable and manipulated it via pointers.

/*
#include <iostream>
using namespace std;
int main(){
	int my_int = 46; // Declare a normal integer variable.
	                 // Set it to equal 46.

	// Declare a pointer and make it point to the variable my_int
	// by using the address-of operator.
	int *my_pointer = &my_int;

	cout << my_int << endl; // Displays 46.

	*my_pointer = 107; // Derefence and modify the variable.

	cout << my_int << endl; // Displays 107.
	cout << *my_pointer << endl; // Also 107.
}
*/

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//we illustrate the use of the delete operator which de-allocates heap memory
// just think of the heap as a free store of memory available to running programs

/*
#include <iostream>
using namespace std;
int main(){
	int *ptr1; // Declare a pointer to int.
	ptr1 = new int; // Reserve storage and point to it.

	float *ptr2 = new float; // Do it all in one statement.

	delete ptr1; // Free the storage.
	delete ptr2;
}
*/

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//In this final example, we show how pointers are used to pass values by reference to a function. This is how we modify the values of variables within a function.
// Passing parameters by reference.

#include <iostream>
using namespace std;

//traditional int function can only return one value
//this one changes three values simultaneously
void Duplicate(int& a, int& b, int& c) {
  a *= 2;
  b *= 3;
  c *= 4;
}

int main() {
  int x = 1, y = 3, z = 7;
  Duplicate(x, y, z);
  // The following outputs: x=2, y=9, z=28.
  cout << c"x="<< x << ", y="<< y << ", z="<< z;
  return 0;
}

//If we were to leave the &'s off the arguments in the 
//Duplicate function definition, we pass the variables "by 
//value", i.e., a copy is made of the value of the variable. 
//Any changes made to the variable in the function modify the 
//copy. They do not modify the original variable.

//When a variable is passed by reference we are not passing a copy of its value, we are passing the address of the variable to the function. Any modification that we do to the local variable actually modifies the original variable passed in. 

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//in this method, only the last variable changes

/*
#include <iostream>
using namespace std;

int Duplicate(int a, int b, int c) {
  a *= 2;
  b *= 3;
  c *= 4;
  return a,b,c;
}

int main() {
  int x = 1, y = 3, z = 7;
  x,y,z = Duplicate(x, y, z);
  // The following outputs: x=2, y=9, z=28.
  cout << "x="<< x << ", y="<< y << ", z="<< z;
  return 0;
}
*/

//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////

//If you are a C programmer, this is a new twist. We could do the same in C by declaring Duplicate() as Duplicate(int *x), in which case x is a pointer to an int, then calling Duplicate() with argument &x (address-of x), and using de-referencing of x within Duplicate() (see below). But C++ provides a simpler way of passing values to functions by reference, even though the old "C" way of doing it still works.

//This is the C way
/*
#include <iostream>
using namespace std;

void Duplicate(int *a, int *b, int *c) {
  *a *= 2;
  *b *= 2;
  *c *= 2;
}

int main() {
  int x = 1, y = 3, z = 7;
  Duplicate(&x, &y, &z);
  // The following outputs: x=2, y=6, z=14.
  cout << "x=" << x << ", y=" << y << ", z=" << z;
  return 0;
}
*/