#include "pokladna.h"
#include "uctenka.h"

int Pokladna::citacld = 0;

Pokladna::Pokladna() {
	poleUctenek = new Uctenka[10];
	pocetVydanychUctenek = 0;
}
//Pokladna::Pokladna() : poleUctenek(new Uctenka[10]), pocetVydanychUctenek(0); //dalsi moznost

Uctenka& Pokladna::vystavUctenku(double castka, double dph) {
	int noveId = citacld++;
	poleUctenek[pocetVydanychUctenek].setCisloUctenky(noveId);
	poleUctenek[pocetVydanychUctenek].setCastka(castka);
	poleUctenek[pocetVydanychUctenek].setDph(dph);

	Uctenka& vracim = poleUctenek[pocetVydanychUctenek];
	pocetVydanychUctenek++;
	return vracim;
}

const Uctenka& Pokladna::dejUctenku(int cislo) {
	for (int i = 0; i < pocetVydanychUctenek; i++) {
		if (poleUctenek[i].getCisloUctenky() == cislo) {
			return poleUctenek[i];
		}
	}
	throw "Chyba dejUctenku";
}

double Pokladna::dejCastku() {
	double suma = 0;
	for (int i = 0; i < pocetVydanychUctenek; i++) {
		suma += poleUctenek[i].getCastka();
	}
	return suma;
}

double Pokladna::dejCastkuVcDph() {
/*	int castkaVcDph = 0;
	int castka = dejCastku();
	for (int i = 0; i < pocetVydanychUctenek; i++) {
		castkaVcDph += (castka *(1+poleUctenek[i].getDph));
	}
	return castkaVcDph;*/
	return 0;
}

Pokladna::~Pokladna() {
	delete poleUctenek;
}