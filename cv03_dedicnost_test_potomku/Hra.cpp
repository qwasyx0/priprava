#include "Hra.h"


Hra::Hra() {
	objekty = new Objekt*[10];
}

void Hra::vlozObjekt(Objekt* o)
{
	objekty[o->getId()] = o;
}

int* Hra::najdiIdStatickychObjektu(double xmin, double xmax, double ymin, double ymax)
{
	return nullptr;
}

PohyblivyObjekt** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r)
{
	return nullptr;
}

PohyblivyObjekt** Hra::najdiPohybliveObjektyVOblasti(double x, double y, double r, double umin, double umax)
{
	return nullptr;
}
