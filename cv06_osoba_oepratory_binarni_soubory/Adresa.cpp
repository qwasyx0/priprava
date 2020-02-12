#include "Adresa.h"
#include <istream>
using namespace std;
Adresa::Adresa()
{
}

Adresa::Adresa(std::string ulice, std::string mesto, int psc)
{
	this->_ulice = ulice;
	this->_mesto = mesto;
	this->_psc = psc;
}

std::string Adresa::getUlice() const
{
	return _ulice;
}

std::string Adresa::getMesto() const
{
	return _mesto;
}

int Adresa::getPsc() const
{
	return _psc;
}

void Adresa::setUlice(std::string ulice)
{
	_ulice = ulice;
}

void Adresa::setMesto(std::string mesto)
{
	_mesto = mesto;
}

void Adresa::setPsc(int psc)
{
	_psc = psc;
}

std::string Adresa::toString() const
{
	return _ulice + " " + _mesto + " " + to_string(_psc);
}

std::ostream& operator<<(std::ostream& os, const Adresa& adresa)
{
	os << adresa.getUlice() << " " << adresa.getMesto() << " " << adresa.getPsc();

	return os;
}

std::istream& operator>>(std::istream& is, Adresa& adresa)
{
	std::string pomocna{};
	int pom;

	is >> pomocna;
	adresa.setUlice(pomocna);

	is >> pomocna;
	adresa.setMesto(pomocna);

	is >> pom;
	adresa.setPsc(pom);

	return is;
}
