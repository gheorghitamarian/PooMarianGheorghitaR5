// numberlist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"NumberList.h"
void NumberList::Init()
{
	int count = 0;

}
bool NumberList::Add(int x)
{
	
		numbers[count] = x;
	 count++;
	if (count >= 10) return false;
	return true;

}
void NumberList::Sort()
{
	
	bool sortat;
	do
	{
		sortat = true;
		for (int i = 0; i < count- 1; i++)
			if (numbers[i] > numbers[i + 1])
			{
				int aux = numbers[i];
				numbers[i] = numbers[i + 1];
				numbers[i + 1] = aux;
				sortat = false;
			}
	} while (!sortat);
}
void NumberList::Print()
{
	for (int i = 0; i < count; i++)
		std:: cout << numbers[i] << " ";
}