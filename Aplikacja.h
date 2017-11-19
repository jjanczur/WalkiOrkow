#pragma once //1 dolaczenie na kompilacje (zamiast #ifndef Nazwa#define Nazwa... #endif )
#include "Dokument.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Wyjatki.h"

using namespace std;

/**
	Klasa steruj¹ca ca³¹ aplikacj¹. Oparta na wzorcu singletona (prywatny konstruktor,
	statyczny wskaznik na samego siebie oraz statyczna funkcja getInstance() ).
	Tworzy dwie armie orkow, wczytuje dane z pliku i dodaje orkow do armii losowo, a potem
	generuje serie bitwe az do przegranej jednej z armii. Wyniki zapisuje graficznie w plikach
	z rozszerzeniem .html zawierajacymi przebieg walk.
*/
class Aplikacja
{
public:
	// Destruktor domyslny
	~Aplikacja();

	// Wzorzec singletona
	static Aplikacja* getInstance ()
	{
		if (!pInstance)
			pInstance = new Aplikacja;
		return pInstance;
	}

	// Wczytuje dane orkow z podanego pliku (jeden wiersz pliku: typ nazwa atak zycie szybkosc inteligencja)
	int wczytajDane (string nazwaPliku);

	// Walka pomiedzy armiami. Zaczyna armia z wieksza wartoscia inteligencji w sumie.
	void bitwa (int runda);

private:
	// Konstruktor dostepny tylko dla funkcji getInstance()
	Aplikacja();

	// Armie przechowujace i zarzadzajace orkami
	Dokument * armia1;
	Dokument * armia2;

	// Statyczny wskaznik na samego siebie
	static Aplikacja * pInstance;

	// Wczytuje dane orka z piku w zalezosci od podanego typu
	int stworzOrka (fstream & plik, string typOrka);

	// Konczy bitwe i wyswietla informacje o zwyciezcy bitwy
	void zwyciestwo (int wygrany);

	// Tworzy plik .html dla odpowiedniej fazy bitwy pomiedzy orkami
	void generujHTML (int runda);
};
