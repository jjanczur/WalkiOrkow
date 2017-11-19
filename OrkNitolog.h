#pragma once
#include "Ork.h"

class OrkNitolog : public Ork
{
public:
	// Domyœlny konstruktor i destruktor
	OrkNitolog();
	virtual ~OrkNitolog();
	OrkNitolog (string nowaNazwa, int nowyAtak, int nowaZycie, int nowaSzybkosc, int nowaInt, int nowaLatanie);
	// Getter i setter dla parametru 'latanie'
	int getLatanie ();
	void setLatanie (int noweLatanie);
	// Przeci¹¿ona funkcja rysowania
	virtual void  rysujOrka (fstream & plik);

protected:
private:
	// Specyficzny dla klasy parametr
	unsigned int latanie;
};
