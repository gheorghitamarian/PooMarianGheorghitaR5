#include "Sort.h"
#include <iostream>
#include <initializer_list>
#include <cstdlib>   
#include <cstdarg>   
#include <cstring>   
#include <stdexcept> 

void Sort::InsertSort(bool ascendent)
{
	for (int i = 1; i < elementsCount; i++)
	{
		int key = elements[i];
		int j = i - 1;
		if (ascendent)
		{
			while (j >= 0 && elements[j] > key)
			{
				elements[j + 1] = elements[j];
				j--;
			}
		}
		else
		{
			while (j >= 0 && elements[j] < key)
			{
				elements[j + 1] = elements[j];
				j--;
			}
		}
		elements[j + 1] = key;
	}
}

void Sort::BubbleSort(bool ascendent)
{
	for (int i = 0; i < elementsCount - 1; i++)
	{
		for (int j = 0; j < elementsCount - i - 1; j++)
		{
			if (ascendent)
			{
				if (elements[j] > elements[j + 1])
				{
					std::swap(elements[j], elements[j + 1]);
				}
			}
			else
			{
				if (elements[j] < elements[j + 1])
				{
					std::swap(elements[j], elements[j + 1]);
				}
			}
		}
	}
}

int Sort::Partition(int low, int high, bool ascendent) {
	int pivot = elements[high];
	int i = low - 1;
	for (int j = low; j < high; j++) {
		if (ascendent) {
			if (elements[j] < pivot) {
				i++;
				std::swap(elements[i], elements[j]);
			}
		}
		else {
			if (elements[j] > pivot) {
				i++;
				std::swap(elements[i], elements[j]);
			}
		}
	}
	std::swap(elements[i + 1], elements[high]);
	return i + 1;
}

void Sort::QuickSortHelper(int low, int high, bool ascendent) {
	if (low < high) {
		int pi = Partition(low, high, ascendent);
		QuickSortHelper(low, pi - 1, ascendent);
		QuickSortHelper(pi + 1, high, ascendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	if (elementsCount > 0) {
		QuickSortHelper(0, elementsCount - 1, ascendent);
	}
}

Sort::~Sort()
{
	delete[] this->elements;
}

Sort::Sort()
{
	this->elementsCount = 0;
	this->elements = nullptr;
}


int Sort::GetElementFromIndex(int index)
{
	if (index >= 0 && index < elementsCount)
	{
		return this->elements[index];
	}
	throw std::out_of_range("Index out of range");
}

Sort::Sort(int elementsCount, int minval, int maxval)
{
	this->elementsCount = elementsCount;
	this->elements = new int[elementsCount];
	for (int i = 0; i < elementsCount; i++)
	{
		this->elements[i] = rand() % (maxval - minval + 1) + minval;
	}
}

Sort::Sort(int* elements, int elementsCount)
{
	this->elementsCount = elementsCount;
	this->elements = new int[elementsCount];
	for (int i = 0; i < elementsCount; i++)
	{
		this->elements[i] = elements[i];
	}
}

Sort::Sort(std::initializer_list<int> list)
{
	this->elementsCount = list.size();
	this->elements = new int[elementsCount];
	int i = 0;
	for (auto& elem : list)
	{
		this->elements[i++] = elem;
	}
}


Sort::Sort(const char* str)
{
	
	int count = 1;
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == ',') count++;
	}

	this->elementsCount = count;
	this->elements = new int[elementsCount];
	int index = 0;
	int currentNumber = 0;
	for (int i = 0; i <= len; i++) {
		if (str[i] == ',' || str[i] == '\0') {
			this->elements[index++] = currentNumber;
			currentNumber = 0; 
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			currentNumber = currentNumber * 10 + (str[i] - '0');
		}
	}
}

int Sort::GetElementsCount()
{
	return this->elementsCount;
}

void Sort::Print()
{
	for (int i = 0; i < elementsCount; i++)
	{
		std::cout << elements[i] << " ";
	}
	std::cout << std::endl;
}

Sort::Sort(int elementsCount, ...)
{
	this->elementsCount = elementsCount;
	this->elements = new int[elementsCount];
	va_list args;
	va_start(args, elementsCount);
	for (int i = 0; i < elementsCount; i++)
	{
		this->elements[i] = va_arg(args, int);
	}
	va_end(args);
}