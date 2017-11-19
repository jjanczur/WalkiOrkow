#include "OrkAdiusz.h"

OrkAdiusz::OrkAdiusz()
{
	// Domyslne parametry
	nazwa = "OrkAdiusz_";
	atak = 1;
	inteligencja = 1;
	szybkosc = 1;
	zycie = 1;
	monety = 100;
}

OrkAdiusz::~OrkAdiusz()
{
}

OrkAdiusz::OrkAdiusz (string nowaNazwa, int nowyAtak, int noweZycie, int nowaSzybkosc, int nowaInt, int noweMonety)
{
	// Konstruktor z konkretnymi wartoœciami parametrów
	this->atak = nowyAtak;
	this->inteligencja = nowaInt;
	this->szybkosc = nowaSzybkosc;
	this->nazwa = nowaNazwa;
	this->zycie = noweZycie;
	this->monety = noweMonety;
}


int OrkAdiusz::getMonety ()
{
	// Getter 
	return monety;
}

void OrkAdiusz::setMonety (int noweMonety)
{
	// Setter
	monety = noweMonety;
}

void  OrkAdiusz::rysujOrka (fstream & plik) {
	// Pobierz dane z odpowiedniego pliku
	ifstream input ("SVG_orkadiusz.html");
	string svg;
	getline (input, svg);

	// Zapisz je do przekazanego pliku .html
	plik << svg << "<br />";
}