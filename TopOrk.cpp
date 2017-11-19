#include "TopOrk.h"

TopOrk::TopOrk ()
{
	// Domyslne parametry
	nazwa = "TopOrk_";
	atak = 1;
	inteligencja = 1;
	szybkosc = 1;
	zycie = 1;
	mana = 1;
}

TopOrk::~TopOrk ()
{
}

TopOrk::TopOrk (string nowaNazwa, int nowyAtak, int noweZycie, int nowaSzybkosc, int nowaInt, int nowaMana)
{
	// Konstruktor z konkretnymi wartoœciami parametrów
	this->atak = nowyAtak;
	this->inteligencja = nowaInt;
	this->szybkosc = nowaSzybkosc;
	this->nazwa = nowaNazwa;
	this->zycie = noweZycie;
	this->mana = nowaMana;
}
// Getter 

int TopOrk::getMana ()
{
	return mana;
}
// Setter
void TopOrk::setMana (int nowaMana)
{
	mana = nowaMana;
}
// Pobierz dane z odpowiedniego pliku
void  TopOrk::rysujOrka (fstream & plik) {
	ifstream input ("SVG_topork.html");
	string svg;
	getline (input, svg);
	// Zapisz je do przekazanego pliku .html
	plik << svg << "<br />";
}