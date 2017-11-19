#pragma once
#include "Ork.h"
#include "TopOrk.h"
#include "OrkAdiusz.h"
#include "OrkNitolog.h"
#include "Orkhybryda.h"
#include <vector>

using namespace std;

/**
	Klasa zarz¹dzaj¹ca elemetami, czyli orkami. Przechowuje wszystkie typy orków w vectorze<Ork*>.
	Udostepnia metody dodawania, usuwania, wydobywania i obliczania parametrów orków.
*/
class Dokument
{
public:
	// Konstruktor i destruktor domyslny
	Dokument();
	~Dokument ();

	// Wrzuca wskazanie na orka do vectora
	void insertOrk (Ork * ork);

	// Usuwa wskazanie z wektora oraz obiekt wskazywany
	void deleteOrk (unsigned int numer);

	// Zwraca wskazanie na orka o podanej pozycji w wektorze
	Ork* getOrk (unsigned int index);

	// Wyswietla statystyki orkow w wektorze (sumy wszystkich parametrow)
	void status ();

	// Oblicza sume konkretnego parametru po wszystkich orkach
	int obliczParametr (int param);

	// Zwraca rozmiar wektora, czyli liczebnosc armii
	unsigned int getSize ();

private:
	// Trzyma wskazania na Ork oraz na klasy po nim dziedzicz¹ce
	vector<Ork*> orkowie;
};
