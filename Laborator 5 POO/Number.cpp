#include "Number.h"
#include <iostream>
#include <cstring>	
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
Number::Number(const char* value, int base)
{
	this->base = base;
	this->digitsCount = strlen(value);
	this->digits = new char[this->digitsCount + 1];
	strcpy(this->digits, value);
}
	
Number::~Number()
{
	delete[] this->digits;
}

void Number::SwitchBase(int newBase)
{
	this->base = newBase;
}

void Number::Print()
{
	std::cout << "Base: " << this->base << ", Digits: " << this->digits << std::endl;
}

int Number::GetDigitsCount()
{
	return this->digitsCount;
}

int Number::GetBase()
{
	return this->base;
}
	
long long Number::GetBase10() const
{
	long long result = 0;
	long long power = 1;
	for (int i = this->digitsCount - 1; i >= 0; --i)
	{
		char digit = this->digits[i];
		int digitValue;
		if (digit >= '0' && digit <= '9')
			digitValue = digit - '0';
		else
			digitValue = digit - 'A' + 10;
		result += digitValue * power;
		power *= this->base;
	}
	return result;
}

void Number::SetFromBase10(long long val, int newBase)
{
	char buffer[65]; // enough for base 2 representation of a 64-bit number
	int index = 0;
	while (val > 0)
	{
		int digitValue = val % newBase;
		buffer[index++] = (digitValue < 10) ? (digitValue + '0') : (digitValue - 10 + 'A');
		val /= newBase;
	}
	buffer[index] = '\0';
	std::reverse(buffer, buffer + index);
	delete[] this->digits;
	this->digitsCount = index;
	this->digits = new char[this->digitsCount + 1];
	strcpy(this->digits, buffer);
	this->base = newBase;
}

Number::Number(const Number& other)
{
	this->base = other.base;
	this->digitsCount = other.digitsCount;
	this->digits = new char[this->digitsCount + 1];
	strcpy(this->digits, other.digits);
}

Number::Number(Number&& other) noexcept
{
	this->base = other.base;
	this->digitsCount = other.digitsCount;
	this->digits = other.digits;
	other.digits = nullptr;
	other.digitsCount = 0;
	other.base = 0;
}

Number& Number::operator=(const Number& other)
{
	if (this != &other)
	{
		delete[] this->digits;
		this->base = other.base;
		this->digitsCount = other.digitsCount;
		this->digits = new char[this->digitsCount + 1];
		strcpy(this->digits, other.digits);
	}
	return *this;
}

Number& Number::operator=(Number&& other) noexcept
{
	if (this != &other)
	{
		delete[] this->digits;
		this->base = other.base;
		this->digitsCount = other.digitsCount;
		this->digits = other.digits;
		other.digits = nullptr;
		other.digitsCount = 0;
		other.base = 0;
	}
	return *this;
}

Number operator+(const Number& n1, const Number& n2)
{
	long long val1 = n1.GetBase10();
	long long val2 = n2.GetBase10();
	long long sum = val1 + val2;
	Number result("0", 10);
	result.SetFromBase10(sum, n1.base);
	return result;
}

Number operator-(const Number& n1, const Number& n2)
{
	long long val1 = n1.GetBase10();
	long long val2 = n2.GetBase10();
	long long diff = val1 - val2;
	Number result("0", 10);
	result.SetFromBase10(diff, n1.base);
	return result;
}

char Number::operator[](int index) const
{
	if (index < 0 || index >= this->digitsCount)
		throw std::out_of_range("Index out of range");
	return this->digits[index];
}

bool Number::operator>(const Number& other) const
{
	return this->GetBase10() > other.GetBase10();
}

bool Number::operator<(const Number& other) const
{
	return this->GetBase10() < other.GetBase10();
}

bool Number::operator>=(const Number& other) const
{
	return this->GetBase10() >= other.GetBase10();
}

bool Number::operator<=(const Number& other) const
{
	return this->GetBase10() <= other.GetBase10();
}
	
bool Number::operator==(const Number& other) const
{
	return this->GetBase10() == other.GetBase10();
}

bool Number::operator!=(const Number& other) const
{
	return this->GetBase10() != other.GetBase10();
}

Number& Number::operator--()
{
	long long val = this->GetBase10();
	--val;
	this->SetFromBase10(val, this->base);
	return *this;
}

Number Number::operator--(int)
{
	Number temp(*this);
	--(*this);
	return temp;
}

