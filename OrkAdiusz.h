#pragma once
#include "Ork.h"

/**
	Klasa pochodna po Ork, zawiera dodatkowy parametr monety, odpowiedni 
	konstruktor szczegółowy i przeciążoną funkcją rysowania
*/
class OrkAdiusz : virtual public Ork
{
public:
	// Domyślny konstruktor i destruktor
	OrkAdiusz();
	virtual ~OrkAdiusz();

	// Kontruktor szczegółowy
	OrkAdiusz (string nowaNazwa, int nowyAtak, int nowaZycie, int nowaSzybkosc, int nowaInt, int noweMonety);

	// Getter i setter dla parametru 'monety'
	int getMonety ();
	void setMonety (int noweMonety);

	// Przeciążona funkcja rysowania
	virtual void  rysujOrka (fstream & plik);

protected:
	// Specyficzny dla klasy parametr
	unsigned int monety;
};
