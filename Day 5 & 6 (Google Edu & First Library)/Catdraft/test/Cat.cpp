#include "Cat.h"
#include <iostream>

namespace caveofprogramming{
    Cat::Cat(){

	}

	void saySomething(){
		std::cout << "Hello there!!" << std::endl;
	}

	void Cat::speak(){
		std::cout << "Meooowww!!!" << std::endl;
	}

	Cat::~Cat(){

	}
}

