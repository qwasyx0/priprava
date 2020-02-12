#pragma once
#include "Objekt.h"
#define _USE_MATH_DEFINES
#include <math.h>

struct PohyblivyObjekt : Objekt {
public:
	PohyblivyObjekt(int id, double uhelNatoceni);
	double getUhelNatoceni()const;
	void setUhelNatoceni(double);
private:
	double uhelNatoceni;
};