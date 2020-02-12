#pragma once
#include "stdafx.h"
#include <string>
#include "TypExtremu.h"
struct Prvek;


using namespace std;
struct SpojovySeznam {

private:
	Prvek * prvni;




public:
	SpojovySeznam();

	Prvek* vloz(const string klic);
	Prvek* najdi(const string klic);
	Prvek* najdiNeboVloz(const string klic);
	Prvek* najdiExtrem(const TypExtremu te);
	bool jePrazdny();
	void vypis(int odsazeni = 0);

	~SpojovySeznam();

};