#include "Objekt.h"

Objekt::Objekt(int id) {
	this->id = id;
}

double Objekt::getX() const
{
	return x;
}

double Objekt::getY() const
{
	return y;
}

void Objekt::setY(double y)
{
	this->y = y;
}

void Objekt::setX(double x)
{
	this->x = x;
}

int Objekt::getId() const
{
	return id;
}
