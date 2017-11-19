#include "Orkhybryda.h"
#include "OrkAdiusz.h"
#include "Wyjatki.h"

Orkhybryda::Orkhybryda()
{
	// Domyslne parametry
	nazwa = "Orkhybryda_";
	atak = 1;
	inteligencja = 1;
	szybkosc = 1;
	zycie = 1;
	mana = 1;
	monety = 100;
}

Orkhybryda::Orkhybryda(string nowaNazwa, int nowyAtak, int noweZycie, int nowaSzybkosc, int nowaInt, int noweMonety, int nowaMana)
{
	// Konstruktor z konkretnymi wartoœciami parametrów
	this->atak = nowyAtak;
	this->inteligencja = nowaInt;
	this->szybkosc = nowaSzybkosc;
	this->nazwa = nowaNazwa;
	this->zycie = noweZycie;
	this->mana = nowaMana;
	this->monety = noweMonety;
}

Orkhybryda::~Orkhybryda()
{
}

void  Orkhybryda::rysujOrka(fstream & plik)
{
	// Pobierz dane z odpowiedniego pliku

	ifstream input("OrkHybryda.html");
	if (!input.good()) throw Wyjatki(0);
	string svg;
	getline(input, svg);

	// Zapisz je do przekazanego pliku .html
	plik << svg << "<br />";
}
