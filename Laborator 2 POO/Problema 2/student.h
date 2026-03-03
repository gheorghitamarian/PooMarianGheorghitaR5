#pragma once

class Student
{
private:
	int varsta;
	char* nume;
	float nota_engleza;
	float nota_matematica;
	float nota_istorie;

public:
	Student() : varsta(0), nume(nullptr), nota_engleza(1.0f), nota_matematica(1.0f), nota_istorie(1.0f) {}

	void SetVarsta(int varsta);
	void SetNotaMatematica(float nota_matematica);
	void SetNotaEngleza(float nota_engleza);
	void SetNotaIstorie(float nota_istorie);
	void SetNume(const char* nume);

	const char* GetNume() const;
	int GetVarsta() const;
	float GetNotaMatematica() const;
	float GetNotaEngleza() const;
	float GetNotaIstorie() const;
	float GetMediaNote() const;
};