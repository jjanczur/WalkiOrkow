#pragma once
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

class Istota
{
public:
	// Wyswietla informacje o parametrach Orka
	virtual string getInfo ()=0;

	// Settery do parametrów
	virtual void setNazwa (string)=0;
	virtual void setZycie (int)=0;

	// Gettery do parametrów
	virtual string getNazwa ()=0;
	virtual int getZycie ()=0;

protected:
	// Parametry
	string nazwa;
	int zycie;
};
