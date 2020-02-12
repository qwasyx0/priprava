#pragma once
#pragma once
#include <string>
#include <iostream>
#ifndef _ADRESA_
#define _ADRESA_

using namespace std;


struct adresa
{
	string _ulice;
	string _mesto;
	int _psc;
	adresa() :_ulice(""), _mesto(""), _psc(0) {}
	adresa(string ul, string me, int ps) :_ulice(ul), _mesto(me), _psc(ps) {}
};
ostream& operator<<(ostream& os, const adresa& adres) {
	os << adres._ulice << " ";
	os << adres._mesto << " ";
	os << adres._psc << " ";
	return os;
}
istream& operator>>(istream& is, adresa& adre) {
	is >> adre._mesto;
	is >> adre._ulice;
	is >> adre._psc;
	return is;
}
#endif