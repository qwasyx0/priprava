#include "PohyblivyObjekt.h"

PohyblivyObjekt::PohyblivyObjekt(int id, double uhelNatoceni) : Objekt(id)
{
	this->uhelNatoceni = uhelNatoceni;
}

double PohyblivyObjekt::getUhelNatoceni()const
{
	return uhelNatoceni;
}

void PohyblivyObjekt::setUhelNatoceni(double uhel)
{
	if (uhel >= 0 && uhel <= 2 * M_PI) {
		uhelNatoceni = uhel;
	}
	else {
		throw "Chyba setUhelNatoceni";
	}
}
