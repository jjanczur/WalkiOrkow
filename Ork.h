#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Istota.h"


using namespace std;

/**
	Element dla dokumentu. Podstawowy typ Orka. Zawiera informacje o nazwie, ataku, zyciu, szybkosci i inteligencji.
	Udostepnia metode wyswietlaj�c� informacje o Orku, konstruktor z parametrami Orka oraz metod� ataku pomi�dzy dwoma Orkami.
	Ponadto zawiera wirtualn� funkcj� rysowania, kt�rej przeci��enia s� w klasach pochodnych.

	Klasy pochodne: TopOrk, OrkNitolog, OrkAdiusz
*/
class Ork: public Istota
{
public:
	// Domyslny konstruktor i destruktor
	Ork ();
	virtual ~Ork ();

	// Konstruktor kopiuj�cy
	Ork (Ork& nowyOrk);

	// Konstruktor z parametrami
	Ork (string nowaNazwa, int nowyAtak, int noweZycie, int nowaSzybkosc, int nowaInt);

	// Funkcja ataku (atakuj�cy wywo�uje metode i podaje broni�cego jako argument).
	void atakuj(Ork * drugiOrk);

	// Wyswietla informacje o parametrach Orka
	string getInfo ();

	// Wypisuje etykiety parametr�w
	static void printLabels ();

	// Pobiera dane SVG i zapisuje do przekazanego w argumencie pliku 'plik'
	virtual void  rysujOrka (fstream & plik);

	// Settery do parametr�w
	void setNazwa (string nowaNazwa);
	void setAtak (int nowyAtak);
	void setSzybkosc (int nowaSzybkosc);
	void setInt (int nowaInt);
	void setZycie (int noweZycie);

	// Gettery do parametr�w
	string getNazwa ();
	int getAtak ();
	int getSzybkosc ();
	int getInt ();
	int getZycie ();

	friend ostream& operator<<(ostream&, Ork*);

protected:
	// Parametry
	//string nazwa;
	unsigned int atak;
	unsigned int szybkosc;
	unsigned int inteligencja;
	//int zycie;
};
