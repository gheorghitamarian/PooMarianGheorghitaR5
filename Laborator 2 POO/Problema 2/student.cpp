
#include "functions.h"
#include <iostream>


void Student::SetVarsta(int varsta)
{
	this->varsta = varsta;
}

int Student::GetVarsta() const
{
	return this->varsta;
}

void Student::SetNume(const char* nume)
{
	if (this->nume != nullptr) {
		delete[] this->nume;
	}
	size_t len = strlen(nume) + 1;
	this->nume = new char[len];
	strcpy_s(this->nume, len, nume);
}

const char* Student::GetNume() const
{
	return this->nume;
}

void Student::SetNotaMatematica(float nota_matematica)
{
	this->nota_matematica = nota_matematica;
}

void Student::SetNotaIstorie(float nota_istorie)
{
	this->nota_istorie = nota_istorie;
}

void Student::SetNotaEngleza(float nota_engleza)
{
	this->nota_engleza = nota_engleza;
}

float Student::GetNotaMatematica() const
{
	return this->nota_matematica;
}

float Student::GetNotaEngleza() const
{
	return this->nota_engleza;
}

float Student::GetNotaIstorie() const
{
	return this->nota_istorie;
}

float Student::GetMediaNote() const
{
	return (this->nota_istorie + this->nota_matematica + this->nota_engleza) / 3.0f;
}