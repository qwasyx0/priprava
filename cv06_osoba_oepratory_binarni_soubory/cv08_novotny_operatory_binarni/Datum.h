#pragma once
#include <string>
#include <iostream>
#ifndef _DATUM_
#define _DATUM_

using namespace std;


	struct datum
	{
		int _den;
		int _mesic;
		int _rok;
		datum() :_den(0), _mesic(0),_rok(0) {}
		datum(int de,int mes,int ro) :_den(de),_mesic(mes),_rok(ro) {}
	};
	ostream& operator<<(ostream& os, const datum& dat) {
		os << dat._den << " ";
		os << dat._mesic << " ";
		os << dat._rok << " ";
		return os;
	}
	istream& operator>>(istream& is, datum& dat) {
		is >> dat._den;
		is >> dat._mesic;
		is >> dat._rok;
		return is;
	}
#endif