#pragma once
#pragma warning(disable:4996)
class Number
{
	// add data members
private:
	char* digits;
	int base;
	int digitsCount;
	long long GetBase10() const;
	void SetFromBase10(long long val, int newBase);
public:
	Number(const char* value, int base); // where base is between 2 and 16
	~Number();
	Number(const Number& other);
	Number(Number&& other) noexcept;
	Number& operator=(const Number& other);
	Number& operator=(Number&& other) noexcept;

	// add operators and copy/move constructor

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);

	char operator[](int index) const;

	bool operator>(const Number& other) const;
	bool operator<(const Number& other) const;
	bool operator>=(const Number& other) const;
	bool operator<=(const Number& other) const;
	bool operator==(const Number& other) const;
	bool operator!=(const Number& other) const;

	Number& operator--();
	Number operator--(int);
};