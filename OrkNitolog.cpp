#include "OrkNitolog.h"

OrkNitolog::OrkNitolog()
{
	// Domyslne parametry
	nazwa = "OrkNitolog_";
	atak = 1;
	inteligencja = 1;
	szybkosc = 1;
	zycie = 1;
	latanie = 1;
}

OrkNitolog::~OrkNitolog()
{
}

OrkNitolog::OrkNitolog (string nowaNazwa, int nowyAtak, int noweZycie, int nowaSzybkosc, int nowaInt, int noweLatanie)
{
	// Konstruktor z konkretnymi wartoœciami parametrów
	this->atak = nowyAtak;
	this->inteligencja = nowaInt;
	this->szybkosc = nowaSzybkosc;
	this->nazwa = nowaNazwa;
	this->zycie = noweZycie;
	this->latanie = noweLatanie;
}
// Getter 
int OrkNitolog::getLatanie ()
{
	return latanie;
}
// Setter
void OrkNitolog::setLatanie (int noweLatanie)
{
	latanie = noweLatanie;
}
// Pobierz dane z odpowiedniego pliku
void  OrkNitolog::rysujOrka (fstream & plik) {
	ifstream input ("SVG_orknitolog.html");
	string svg;
	getline (input, svg);
	// Zapisz je do przekazanego pliku .html
	plik << svg << "<br />";
}
