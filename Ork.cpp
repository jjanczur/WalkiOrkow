#include "Ork.h"

Ork::Ork ()
{
	// Wartoœci domyslne(zabezpieczenie zeby nic nie bylo wczytywane losowo z pamieci)
	nazwa = "";
	atak = 1;
	inteligencja = 1;
	szybkosc = 1;
	zycie = 1;
}

Ork::~Ork ()
{
}

Ork::Ork (Ork& nowyOrk)
{
	// Kopiuje wartosci z nowegoOrka do wo³aj¹cego metodê
	this->nazwa = nowyOrk.getNazwa();
	this->atak = nowyOrk.getAtak();
	this->inteligencja = nowyOrk.getInt();
	this->szybkosc = nowyOrk.getSzybkosc();
	this->zycie = nowyOrk.getZycie();
}

Ork::Ork (string nowaNazwa, int nowyAtak, int noweZycie, int nowaSzybkosc, int nowaInt)
{
	// Konstruktor z konkretnymi wartoœciami parametrów
	this->atak = nowyAtak;
	this->inteligencja = nowaInt;
	this->szybkosc = nowaSzybkosc;
	this->nazwa = nowaNazwa;
	this->zycie = noweZycie;
}

string Ork::getInfo ()
{
	// Wyswietla sformatowane wartosci parametrów
	return "\t"+ nazwa + "\t" + to_string(atak) + "\t" + to_string(zycie) + "\t" + to_string(szybkosc)	+ "\t" + to_string(inteligencja) +"\n";
}

void Ork::printLabels () {
	// Wyswietla sformatowane etykiety dla parametrów
	cout << "\tNazwa\tAtak\tZycie\tSzybk.\tIntel.\n";
}

void Ork::atakuj (Ork * drugiOrk)
{
	// Wo³aj¹cy metodê atakuje orka podanego w argumencie
	cout << "\n### Do ataku!!!! ###\n";
	cout << "\t" << this->nazwa << "  vs.  " << drugiOrk->getNazwa ();  // Kto z kim walczy?
	cout << "\tArhg...uhgh...auu...sss...BOOM!\n";

	// Pobierz zycie broni¹cego i odejmij od niego atak napastnika
	int zycieOrka = drugiOrk->getZycie();
	zycieOrka -= this->atak;
	drugiOrk->setZycie(zycieOrka);	// Ustaw zranionemu now¹ wartoœæ ¿ycia

	// Informacje o poniesionych obra¿eniach
	cout << "\t" << drugiOrk->getNazwa() << " stracil: " << this->atak << endl;
	printLabels ();
	// Informacje o walcz¹cych
	cout<<this->getInfo ();
	cout<<drugiOrk->getInfo ();
}

void  Ork::rysujOrka (fstream & plik) {
	// Pobierz dane z odpowiedniego pliku
	ifstream input ("SVG_ork.html");
	string svg;
	getline (input, svg);

	// Zapisz je do przekazanego pliku .html
	plik << svg << "<br />";
}

// SETTERY
void Ork::setNazwa (string nowaNazwa)
{
	nazwa = nowaNazwa;
}

void Ork::setAtak (int nowyAtak)
{
	atak = nowyAtak;
}

void Ork::setSzybkosc (int nowaSzybkosc)
{
	szybkosc = nowaSzybkosc;
}

void Ork::setInt (int nowaInt)
{
	inteligencja = nowaInt;
}

void Ork::setZycie (int noweZycie)
{
	zycie = noweZycie;
}

// GETTERY
string Ork::getNazwa ()
{
	return nazwa;
}

int Ork::getAtak ()
{
	return atak;
}

int Ork::getSzybkosc ()
{
	return szybkosc;
}

int Ork::getInt ()
{
	return inteligencja;
}

int Ork::getZycie ()
{
	return zycie;
}

ostream& operator<<(ostream& wy, Ork* we){
    return wy<<we->getInfo ();
}

