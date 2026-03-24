#include<iostream>
#include "Number.h"

int main()
{
	Number n1("1010", 2);
	Number n2("A", 16);
	n1.Print();
	n2.Print();
	Number sum = n1 + n2;
	sum.Print();
	Number diff = n1 - n2;
	diff.Print();
	std::cout << "n1[0]: " << n1[0] << std::endl;
	if (n1 > n2)
		std::cout << "n1 este mai mare decat n2" << std::endl;
	else if (n1 < n2)
		std::cout << "n1 este mai mic decat n2" << std::endl;
	else
		std::cout << "n1 este egal cu  n2" << std::endl;
	return 0;
}
