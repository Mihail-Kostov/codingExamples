#include <iostream>
#include <cmath>
#include <vector>

int main()
{
	// Variable
	int i = 3;
	std::cout << "Creating variable i:\n-> i = 3" << std::endl;
	std::cout << "Printing i: " << i << std::endl;
	std::cout << std::endl;

	// Pointer
	int *p = &(i);
	std::cout << "Creating pointer p (*), giving it the address of i (&):\n-> int *p = &(i)" << std::endl;
	std::cout << "(p is a pointer referring to the address of i)" << std::endl;
	std::cout << "Printing p: " << p << std::endl;
	std::cout << std::endl;

	int b = *p;
	std::cout << "Dereferencing p to b:\n-> int b = *p" << std::endl;
	std::cout << "(b is now an int which copied the value of a, by going at the address indicated by p, and copying the values stored in it)" << std::endl;
	std::cout << "Printing *p:  " << *p << std::endl;
	std::cout << "Printing b: " << b << std::endl;
	std::cout << std::endl;

	int &r = i;
	int c = i;
	std::cout << "Creating a reference to i:\n-> int &r = i;" << std::endl;
	std::cout << "Creating a copy of i:\n-> int c = i;" << std::endl;
	std::cout << "(r now is a reference of i. It's the same object in memory. It's basically a shortcut or a link to i, it doesn't occupy any additional memory. c is a copy of i, it takes the same value, but it's a different memory address which copied the content of i)" << std::endl;
	std::cout << "Printing r:  " << r << std::endl;
	std::cout << "Printing c: " << c << std::endl;
	std::cout << "Printing &i:  " << &i << std::endl;
	std::cout << "Printing &r:  " << &r << std::endl;
	std::cout << "Printing &c: " << &c << std::endl;
	std::cout << "(r and i have the same address. They are the same thing.)" << std::endl;
	std::cout << std::endl;

	i = 5;
	std::cout << "Changing value of i:\n-> i = 5" << std::endl;
	std::cout << "Printing i:  " << i << std::endl;
	std::cout << "Printing r:  " << r << std::endl;
	std::cout << "Printing c: " << c << std::endl;
	std::cout << "Printing &i:  " << &i << std::endl;
	std::cout << "Printing &r:  " << &r << std::endl;
	std::cout << "Printing &c: " << &c << std::endl;
	std::cout << "(r changed as well! c stayed the same)" << std::endl;
	std::cout << std::endl;

	r = 7;
	std::cout << "Changing value of r:\n-> r = 7" << std::endl;
	std::cout << "Printing i:  " << i << std::endl;
	std::cout << "Printing r:  " << r << std::endl;
	std::cout << "Printing c: " << c << std::endl;
	std::cout << "Printing &i:  " << &i << std::endl;
	std::cout << "Printing &r:  " << &r << std::endl;
	std::cout << "Printing &c: " << &c << std::endl;
	std::cout << "(Works also the other way round! i changed now. c stayed the same)" << std::endl;
	std::cout << std::endl;

	return 0;
}