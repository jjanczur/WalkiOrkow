#pragma once
#include "Ork.h"

/**
	Klasa pochodna po Ork, zawiera dodatkowy parametr monety, odpowiedni 
	konstruktor szczeg�owy i przeci��on� funkcj� rysowania
*/
class OrkAdiusz : virtual public Ork
{
public:
	// Domy�lny konstruktor i destruktor
	OrkAdiusz();
	virtual ~OrkAdiusz();

	// Kontruktor szczeg�owy
	OrkAdiusz (string nowaNazwa, int nowyAtak, int nowaZycie, int nowaSzybkosc, int nowaInt, int noweMonety);

	// Getter i setter dla parametru 'monety'
	int getMonety ();
	void setMonety (int noweMonety);

	// Przeci��ona funkcja rysowania
	virtual void  rysujOrka (fstream & plik);

protected:
	// Specyficzny dla klasy parametr
	unsigned int monety;
};
