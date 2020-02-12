#pragma once
#ifndef _POKLADNA_H
#define _POKLADNA_H
#include "Uctenka.h"
//struct Uctenka; //aby to nehlasilo chybu
struct Pokladna
{
private:
	Uctenka* poleUctenek;/* = new Uctenka[10]*/;
	int pocetVydanychUctenek;
	static int citacld;
public:
	Pokladna();
	Uctenka& vystavUctenku(double, double);
	const Uctenka& dejUctenku(int);
	double dejCastku();
	double dejCastkuVcDph();
	~Pokladna();
};


#endif