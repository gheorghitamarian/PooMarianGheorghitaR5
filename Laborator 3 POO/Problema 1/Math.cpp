#include <iostream>
#include "Math.h"
#include <cstring>
#include <cstdarg>
#include "functions.h"
#pragma warning(disable:4996)
int Math::Add(int a, int b)
{
	return a + b;
}
int Math::Add(int a, int b, int c)
{
	return a + b + c;
}
int Math::Add(double a, double b)
{
	return a + b;
}	
int Math::Add(double a, double b, double c)
{
	return a + b + c;
}
int Math::Mul(int a, int b)
{
	return a * b;
}
int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}
int Math::Mul(double a, double b)
{
	return a * b;
}
int Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	va_list args;
	va_start(args, count);
	int sum = 0;
	for (int i = 1; i <= count; ++i)
	{
		sum += va_arg(args, int);
	}
	va_end(args);
	return sum;
}
char* Math::Add(char* str1, const char* str2)
{
	char* result = new char[strlen(str1) + strlen(str2) + 1];
	strcpy(result, str1);
	strcat(result, str2);
	return result;
}