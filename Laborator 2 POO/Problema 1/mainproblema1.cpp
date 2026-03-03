#include <iostream>
#include "NumberList.h"

NumberList myList;


int main()
{
	myList.Init();
	myList.Add(5);
	myList.Add(4);
	myList.Add(56);
	myList.Add(7);
	myList.Add(2);
	myList.Add(6);
	myList.Add(1);
	myList.Add(2);
	myList.Sort();
	myList.Print();
	


}