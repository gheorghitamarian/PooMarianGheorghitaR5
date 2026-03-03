
#include <iostream>
#include "student.h"
#include "functions.h"

int main()
{
	Student student1, student2;
	student1.SetNume("Vasile");
	student1.SetVarsta(21);
	student1.SetNotaMatematica(9);
	student1.SetNotaEngleza(5);
	student1.SetNotaIstorie(10);

	student2.SetNume("Cristina");
	student2.SetVarsta(18);
	student2.SetNotaMatematica(4);
	student2.SetNotaEngleza(8);
	student2.SetNotaIstorie(10);


	std::cout << student1.GetNume() <<" "<< "Media: " << student1.GetMediaNote() << std::endl;
	std::cout << student2.GetNume() <<" "<< "Media: " << student2.GetMediaNote() << std::endl;
	
	std::cout << "Comparare Matematica: " << CompNotaMatematica(student1, student2) << std::endl;
	std::cout << "Comparare Engleza: " << CompNotaEngleza(student1, student2) << std::endl;
	std::cout << "Comparare Nume: " << CompNume(student1, student2) << std::endl;

}
