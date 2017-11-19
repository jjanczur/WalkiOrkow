#include "Dokument.h"

Dokument::Dokument()
{

}

Dokument::~Dokument()
{
	// Iterowanie przez wektor i dealokacja danych.
	for (Ork * x : orkowie) {
		delete x;
	}
}

void Dokument::insertOrk(Ork * ork)
{
	// Dodaje wskazanie na orka na koniec wektora
	orkowie.push_back(ork);
}

void Dokument::deleteOrk (unsigned int numer) {
	Ork * ork = nullptr;
	if (numer == orkowie.size () - 1) {		// Jesli to ostatni ork to usun z wektora
		ork = orkowie[numer];
		orkowie.pop_back ();
	}
	else if (numer >= 0 && numer < orkowie.size ()) {	// W.p.p. na jego miejsce wstaw ostatniego i usun ostatniego
		ork = orkowie[numer];
		orkowie[numer] = orkowie[orkowie.size ()-1];
		orkowie.pop_back ();
	}

	// Zwalnia pamieæ dla usuniêtego z wektora wskaŸnika
	delete ork;
}

Ork* Dokument::getOrk(unsigned int index)
{
	// Zwróæ orka, jeœli numer nie przekracza rozmiaru vect
	if (index < orkowie.size())
		return orkowie[index];
	else
		return nullptr;		// W.p.p. zwróæ nullptr
}

void Dokument::status () {
	// Wypisuje status wszystkich orków.
	for (unsigned int i = 0; i < orkowie.size (); ++i)		// Najpierw info o kazdym orku osobno
		cout<<orkowie[i]->getInfo();

	// A na koñcu zsumowane wszystkie parametry
	cout << "\tSUMA\t" << obliczParametr (0) << "\t" << obliczParametr (1) << "\t" << obliczParametr (2) << "\t" << obliczParametr (3) << "\n";
}

int Dokument::obliczParametr (int param) {
	// Zwraca zsumowany parametr po wszystkich orkach.
	int suma = 0;
	for (unsigned int i = 0; i < orkowie.size (); ++i) {
		switch (param) {			// Ktory parametr sumujemy, zalezy od argumentu 'param'
			case 0: suma += orkowie[i]->getAtak (); break;
			case 1: suma += orkowie[i]->getZycie (); break;
			case 2: suma += orkowie[i]->getSzybkosc (); break;
			case 3: suma += orkowie[i]->getInt (); break;
			default: break;
		}
	}
	return suma;
}

unsigned int Dokument::getSize () {
	// Zwraca liczebnosc armii
	return orkowie.size ();
}
