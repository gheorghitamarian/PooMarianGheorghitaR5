#include<iostream>
#include "Sort.h"
int main()
{
	Sort s1(10, 0, 100);
	std::cout << "Vector initial: ";
	s1.Print();
	
	s1.InsertSort(true);
	std::cout << "Vector sortat  ascendent: ";
	s1.Print();
	
	s1.QuickSort(false);
	std::cout << "Vector sortat  descendent: ";
	s1.Print();
	

	return 0;
}