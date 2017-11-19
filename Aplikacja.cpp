#include "Aplikacja.h"

// Inicjacja statycznego pola klasy
Aplikacja* Aplikacja::pInstance = nullptr;

Aplikacja::Aplikacja()
{
	armia1 = new Dokument;
	armia2 = new Dokument;
}

Aplikacja::~Aplikacja()
{
	delete armia1;
	delete armia2;
}

int Aplikacja::wczytajDane (string nazwaPliku)
{
	fstream plik;
	stringstream stream;
	plik.open (nazwaPliku, std::ios::in);		// Otwarcie pliku do odczytu
	if (plik.good () == true) {
		cout << ">>> Uzyskano dostep do pliku z danymi Orkow. Rozpoczynam rekrutacje.\n\n";
		while (!plik.eof ()) {
			string typOrka;		// Wczytaj typ i przekaz dalej tworzenie orka
			plik >> typOrka;
			cout << "- Rekrutacja orka typu  " << typOrka << "  do armii " << stworzOrka (plik, typOrka) << endl;
		}
	}
	else {
		// Niepowodzenie otwarcie pliku, wyjdz z kodem bledu.
		//std::cout << "### Dostep do pliku zabroniony! ### " << std::endl;
		throw Wyjatki(3);
		plik.close ();
		return 1;
	}

	// Wygeneruj grafiki dla stanu poczatkowego armii
	generujHTML (0);
	return 0;
}

int Aplikacja::stworzOrka (fstream & plik, string typOrka)
{
	string nazwa;
	int atak, zycie, sila, inteligencja;

	// Wczytaj dane jednakowe dla kazdego typu orka (>> -wczytuje do napotkania znaku bia³ego)
	plik >> nazwa >> atak >> zycie >> sila >> inteligencja;

	// Wybierz numer armii losowo (modulo 2 czyli 0 i 1 gdyby % 2+1 to od 1 lub 2)
	int nrArmii = rand () % 2;

	// W zaleznosci od typu orka, tworz odpowiedni obiekt i przydzielaj do odpowiedniej armii
	if (typOrka == "Ork") {
		Ork * pOrk = new Ork (nazwa, atak, zycie, sila, inteligencja);
		nrArmii == 0 ? armia1->insertOrk (pOrk) : armia2->insertOrk (pOrk); // jezeli nr = 0 to przydziel do armi 1 w przeciwnym wypadku do armi 2 analogicznie w ponizszych przypadkach
	}
	else if (typOrka == "TopOrk") {
		int mana;
		plik >> mana;
		TopOrk * pOrk = new TopOrk (nazwa, atak, zycie, sila, inteligencja, mana);
		nrArmii == 0 ? armia1->insertOrk (pOrk) : armia2->insertOrk (pOrk);
	}
	else if (typOrka == "OrkNitolog") {
		int latanie;
		plik >> latanie;
		OrkNitolog * pOrk = new OrkNitolog (nazwa, atak, zycie, sila, inteligencja, latanie);
		nrArmii == 0 ? armia1->insertOrk (pOrk) : armia2->insertOrk (pOrk);
	}
	else if (typOrka == "OrkAdiusz") {
		int monety;
		plik >> monety;
		OrkAdiusz * pOrk = new OrkAdiusz (nazwa, atak, zycie, sila, inteligencja, monety);
		nrArmii == 0 ? armia1->insertOrk (pOrk) : armia2->insertOrk (pOrk);
	}
	else if (typOrka=="Orkhybryda") {
        int monety1;
        int mana1;
        plik >> monety1 >> mana1;
        Orkhybryda * pOrk = new Orkhybryda (nazwa, atak, zycie, sila, inteligencja, monety1, mana1);
		nrArmii == 0 ? armia1->insertOrk (pOrk) : armia2->insertOrk (pOrk);

	}
	else cout << "Bledny typ orka: " << typOrka << endl; // Nie rozpoznano typu orka

	// Zwroc numer przydzielonej armii dla danego orka (1 albo 2)
	return nrArmii + 1;
}

void Aplikacja::bitwa (int runda) {
	unsigned int intel1, intel2;

	// Wczytaj sumaryczna inteligencje armii by wiedziec kto zaczyna
	intel1 = armia1->obliczParametr (3);
	intel2 = armia2->obliczParametr (3);

	// Warunki konca: Inteligencja ktorejs armii jest zerowa (brak orkow)
	if (intel1 == 0 || intel2 == 0) {
		if (intel1 == 0) {
			zwyciestwo (2);
			return;
		}
		else if (intel2 == 0) {
			zwyciestwo (1);
			return;
		}
		else	// Niespodziewany blad
			throw Wyjatki(4);// ("Ciemne moce zawladnely kraina orkow!!! Bitwy nie da sie roztrzygnac!!!");
	}
	else if (intel1 >= intel2) {	// Armia 1 zaczyna walke.
		// Armia1 atakuje armia2(unsigned int bo  w kontenerze wszystko jest zawsze dodatnie bez unsigned wyskakuja warningi
		for (unsigned int i = 0; i < armia1->getSize (); ++i) {
				// Wybierz atakujacego i broniacego sie
			Ork * atakujacy = armia1->getOrk (i);
			Ork * broniacy = armia2->getOrk (armia2->getSize()-1);//biore ostatniego orka w kontenerze -1 bo numeracja orkow jak w tablicy
				// Jezeli wskazania nie sa nullptr'ami, atakuj.
			if (broniacy != nullptr && atakujacy != nullptr) {
				atakujacy->atakuj (broniacy);
				if (broniacy->getZycie () <= 0)		// Sprawdzenie, czy oponent zgladzony
					armia2->deleteOrk (armia2->getSize () - 1);		// Wtedy usuwamy pokonanego.
			}
			else
				break;
		}

		// Armia2 atakuje armia1
		for (unsigned int i = 0; i < armia2->getSize(); ++i) {		// Analogicznie jak wyzej (dalej tez to samo)
			Ork * atakujacy = armia2->getOrk (i);
			Ork * broniacy = armia1->getOrk (armia1->getSize () - 1);
			if (broniacy != nullptr && atakujacy != nullptr) {
				atakujacy->atakuj (broniacy);
				if (broniacy->getZycie () <= 0)
					armia1->deleteOrk (armia1->getSize () - 1);
			}
			else
				break;
		}
	}
	else {		// Armia 2 ma wyzsza inteligencje, wiec zaczyna
		// Armia2 atakuje armia1
		for (unsigned int i = 0; i < armia2->getSize (); ++i) {		// ....
			Ork * atakujacy = armia2->getOrk (i);
			Ork * broniacy = armia1->getOrk (armia1->getSize () - 1);
			if (broniacy != nullptr && atakujacy != nullptr) {
				atakujacy->atakuj (broniacy);
				if (broniacy->getZycie () <= 0)
					armia1->deleteOrk (armia1->getSize () - 1);
			}
			else
				break;
		}

		// Armia1 atakuje armia2
		for (unsigned int i = 0; i < armia1->getSize (); ++i) {		// ....
			Ork * atakujacy = armia1->getOrk (i);
			Ork * broniacy = armia2->getOrk (armia2->getSize () - 1);
			if (broniacy != nullptr && atakujacy != nullptr) {
				atakujacy->atakuj (broniacy);
				if (broniacy->getZycie () <= 0)
					armia2->deleteOrk (armia2->getSize () - 1);
			}
			else
				break;
		}
	}

	// Wyswietl status po bitwie
	cout << "\n>>> Status bitwy " << runda << ":\n";
	cout << "\t\tARMIA 1 \n";
	Ork::printLabels ();
	armia1->status ();
	cout << "\n\t\tARMIA 2 \n";
	Ork::printLabels ();
	armia2->status ();
	cin.get ();

	// Wygeneruj grafike dla tej bitwy
	generujHTML (runda);

	// Inicjuj kolejna bitwe
	bitwa (runda+1);
}

void Aplikacja::zwyciestwo (int wygrany) {
	// Wyswietla komunikat o zwyciezcy walki
	cout << "\n<<<<<< KONIEC BITWY !!! >>>>>>\n\n";
	cout << "\tZwycieza armia " << wygrany << " !!!\n\tFLAWLESSSSS VIIIICTORRYYYYYY!!!!!\n\n";
}

void Aplikacja::generujHTML (int runda){
	// £ancuchy znakowe trzymajace nazwy plikow i tytuly zalezne od bitwy
	string tytul;
	string nextBitwa, prevBitwa;
	string nextCount, prevCount;

	// Operacje na nazwach plików
	fstream plik;
	if (runda == 0) {
		// Stan przed walk¹: plik 'index.html', specjalny tytu³.
		plik.open ("bitwy/index.html", std::ios::out | std::ios::trunc);
		tytul = "<h1 style=\"color:white;\">Stan orków przed starciem";
	}
	else {
		// Ktora bitwa z kolei - konieczna konwersja numeru bitwy na ³ancuch znakowy.
		// Potrzeba konkretnego tytulu i specjalnych nazwa plikow dla hiper³¹czy pomiedzy bitwami.
		stringstream ss;	// Konwersja dla ³¹cza wstecz (runda - 1)
		ss << (runda - 1);
		prevCount = ss.str ();
		prevBitwa = "bitwa" + prevCount;
		ss.str ("");
		ss << (runda + 1);		// Konwersja dla ³acza naprzod (runda + 1)
		nextCount = ss.str ();
		nextBitwa = "bitwa" + nextCount;
		ss.str ("");
		ss << runda;		// Konwersja dla obecnego pliku dla tytlu (runda)
		string nazwa = ss.str ();
		tytul = "<h1 style=\"color:white;\">Bitwa nr " + nazwa;
		nazwa = "bitwy/bitwa" + nazwa + ".html";
		plik.open (nazwa, std::ios::out);	// Otwarcie pliku bitwy.
		if(!plik.good()) throw Wyjatki(1);
	}

	// Stany liczbowe armii
	int liczebnosc1 = armia1->getSize ();
	int liczebnosc2 = armia2->getSize ();

	// Podstawowe znaczniki HTML
	string naglowek, css, body, table, stopka, next, prev;
	naglowek = "<html><head><title>Bitwa Orków !!! - Projekt Jacka Janczury [PROE]</title>";	// Tytul strony
	css = " <style type=\"text/css\">a { color: white; font-size: 16pt; } a:visited {color: white;} a:hover {color: orange;}</style></head>";	// Formatowanie tekstu i laczy
	body = "<body background = \"http://www.art.eonworks.com/free/textures/rough_terrain_texture_24-512x512.png\">";	// Znacznik body plus tlo
	table = "<table align=\"center\" width = \"800px\"><tr align=\"center\"><td colspan=2>";  // Uklad strony w postaci tabeli po 1 stronie 1 armia po 2. 2. armia
	stopka = "</td></tr></table></body></html>";  // Koncowe zamkniecia znacznikow


	if (runda == 0) {	// Jesli stan przed walk¹
		prev = "";		// £¹cze wstecz puste
		if (liczebnosc1 == 0 || liczebnosc2 == 0) {		// Jesli ktora armia przegrala, poinformuj o koncu walki
			liczebnosc1 == 0 ? tytul += " - ZWYCIESTWO ARMII 2 !!!" : tytul += " - ZWYCIESTWO ARMII 1 !!!";
			next = "";		// Brak ³¹cza do nast. bitwy
		}
		else
			next = "<a href=\"bitwa1.html\">BITWA 1 >>></a>";	// W.p.p. utwórz ³¹cze naprzód
	}
	else if (runda == 1) {		// Jeœli pierwsza bitwa
		prev = "<a href=\"index.html\"><<< STAN PRZED BITWA</a>";		// Utwórz specjalne ³¹cze wstecz
		if (liczebnosc1 == 0 || liczebnosc2 == 0) {		// Jesli ktora armia przegrala, poinformuj o koncu walki
			liczebnosc1 == 0 ? tytul += " - ZWYCIESTWO ARMII 2 !!!" : tytul += " - ZWYCIESTWO ARMII 1 !!!";
			next = "";
		}
		else
			next = "<a href=\"bitwa2.html\">BITWA 2 >>></a>";	// W.p.p. utwórz ³¹cze naprzód
	}
	else {		// Jesli n-ta bitwa (n > 1)
		prev = "<a href=\"" + prevBitwa + ".html\"><<< BITWA" + prevCount + "</a>";		// Utworz ³¹cze do poprzedniej bitwy
		if (liczebnosc1 == 0 || liczebnosc2 == 0) {		// Jesli ktora armia przegrala, poinformuj o koncu walki
			liczebnosc1 == 0 ? tytul += " - ZWYCIESTWO ARMII 2 !!!" : tytul += " - ZWYCIESTWO ARMII 1 !!!";
			next = "";
		}
		else
			next = "<a href=\"" + nextBitwa + ".html\">BITWA " + nextCount + ">>></a>";		// W.p.p. utwórz ³¹cze naprzód
	}

	// Zapisz znaczniki do pliku .html
	plik << naglowek << css << body << table << tytul << "</h1></td></tr><tr><td>";

	// Rysowanie armii 1
	for (unsigned i = 0; i < armia1->getSize (); ++i) {
		armia1->getOrk (i)->rysujOrka (plik);
	}

	plik << "</td><td>";

	// Rysowanie armii 2
	for (unsigned i = 0; i < armia2->getSize (); ++i) {
		armia2->getOrk (i)->rysujOrka (plik);
	}

	// Koniec rysowania grafik
	plik << "</td></tr><tr align=\"center\"><td>";

	// Umieszczenie hiper³¹czy
	plik << "<br />" << prev << "</td><td><br />" << next;

	// Zakoñczenie pliku .html (koñcowe znaczniki)
	plik << stopka;
	plik.close ();
}

