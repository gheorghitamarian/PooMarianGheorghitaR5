

#include <iostream>
#include "Math.h"
#pragma warning(disable:4996)
Math mate;

int main()
{
	std::cout << mate.Add(1, 2) << '\n';
	std::cout << mate.Add(1, 2, 3) << '\n';
	
	std::cout << mate.Add(1.5, 2.7) << '\n';
	std::cout << mate.Add(1.5, 2.7, 3.2) << '\n';

	std::cout << mate.Mul(3, 4) << '\n';	
	std::cout << mate.Mul(3, 4, 5) << '\n';	

	std::cout << mate.Mul(2.5, 4.0) << '\n';	
	std::cout << mate.Mul(2.5, 4.0, 3.0) << '\n';

	std::cout << mate.Add(5, 1, 2, 3, 4, 5) << '\n'; 
	char str1[100] = "Andrei";
	char str2[] = "Marius";
	std::cout<< mate.Add(str1, str2);
		

	
}

   

