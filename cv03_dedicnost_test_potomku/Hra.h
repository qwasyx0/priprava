#pragma once
#include "Objekt.h"
#include "PohyblivyObjekt.h"

struct Hra {
public:
	Hra();
	void vlozObjekt(Objekt* o);
	int* najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax);
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r);
	PohyblivyObjekt** najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax);

private:
	Objekt** objekty;
};