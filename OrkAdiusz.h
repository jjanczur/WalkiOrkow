#pragma once
#include "Ork.h"

/**
	Klasa pochodna po Ork, zawiera dodatkowy parametr monety, odpowiedni 
	konstruktor szczegó³owy i przeci¹¿on¹ funkcj¹ rysowania
*/
class OrkAdiusz : virtual public Ork
{
public:
	// Domyœlny konstruktor i destruktor
	OrkAdiusz();
	virtual ~OrkAdiusz();

	// Kontruktor szczegó³owy
	OrkAdiusz (string nowaNazwa, int nowyAtak, int nowaZycie, int nowaSzybkosc, int nowaInt, int noweMonety);

	// Getter i setter dla parametru 'monety'
	int getMonety ();
	void setMonety (int noweMonety);

	// Przeci¹¿ona funkcja rysowania
	virtual void  rysujOrka (fstream & plik);

protected:
	// Specyficzny dla klasy parametr
	unsigned int monety;
};
