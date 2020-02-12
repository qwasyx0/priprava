#pragma once
#include <string>
#include "Adresa.h"
#include"Datum.h"
#ifndef _OSOBA_
#define _OSOBA_

using namespace std;


struct osoba
{
	string _jmeno;
	string _prijmeni;
	adresa _trvaleBydliste;
	datum _datumNarozeni;
	osoba() :_jmeno(""), _prijmeni(""), _trvaleBydliste("","",0) {}
	osoba(string jm, string pr, adresa ad,datum da) :_jmeno(jm),_prijmeni(pr),_trvaleBydliste(ad),_datumNarozeni(da) {}
};
ostream& operator<<(ostream& os, const osoba& osob) {
	os << osob._jmeno << " ";
	os << osob._prijmeni << " ";
	os << osob._trvaleBydliste << " ";
	os << osob._datumNarozeni << " ";
	return os;
}
istream& operator>>(istream& is, osoba& osob) {
	is >> osob._jmeno;
	is >> osob._prijmeni;
	is >> osob._trvaleBydliste;
	is >> osob._datumNarozeni;
	return is;
}
#endif