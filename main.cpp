#include <iostream>
#include <string>
#include "Ork.h"
#include "TopOrk.h"
#include "OrkAdiusz.h"
#include "OrkNitolog.h"
#include "Dokument.h"
#include "Aplikacja.h"
#include "Wyjatki.h"

using namespace std;

int main ()
{
	try
	{
		srand((unsigned int)time(NULL));	// Losowe ziarno dla funkcji randomizujacej

		Aplikacja * aplikacja = Aplikacja::getInstance();	// Obiekt aplikacji (tylko jeden - wzorzec Singletona :D)
		if (aplikacja->wczytajDane("daneOrkow.txt"))		// Wczytanie danych o orkach i przydzia³ do armii.
			throw Wyjatki(2);		// Funkcja wczytujaca zwrocila blad
		else
		{

			cout << "\n>>> Orki gotowe do bitwy.....FIGHT!!! [press ENTER]";
			cin.get();

			aplikacja->bitwa(1);			// Rozpoczecie rekurencyjnej serii bitew pomiedzy dwoma armiami orkow.

			// Koniec programu.
			cout << "W celu zobaczenia postepow bitwy, prosze otworzyc plik bitwy/index.html w katalogu projektu.\n\tPress ENTER to continue...";
		}
	}
	catch (Wyjatki &wyj) {};
	cin.get ();
	return 0;
}
