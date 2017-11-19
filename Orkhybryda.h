#pragma once
#include "OrkAdiusz.h"
#include "TopOrk.h"
#include "OrkAdiusz.h"
#include "TopOrk.h"

class Orkhybryda: public TopOrk, OrkAdiusz
{
public:
	Orkhybryda();
	Orkhybryda(string nowaNazwa, int nowyAtak, int noweZycie, int nowaSzybkosc, int nowaInt, int noweMonety, int nowaMana);
	virtual ~Orkhybryda();
	virtual void rysujOrka(fstream & plik);
};

