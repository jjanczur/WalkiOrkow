#pragma once
#include "Ork.h"

class TopOrk : virtual public Ork
{
public:
	// Domyślny konstruktor i destruktor
	TopOrk ();
	virtual ~TopOrk();
	TopOrk (string nowaNazwa, int nowyAtak, int nowaZycie, int nowaSzybkosc, int nowaInt, int nowaMana);
	// Getter i setter dla parametru 'mana'
	int getMana ();
	void setMana (int nowaMana);
	// Przeciążona funkcja rysowania
	virtual void  rysujOrka (fstream & plik);

protected:
	// Specyficzny dla klasy parametr
	unsigned int mana;
};
