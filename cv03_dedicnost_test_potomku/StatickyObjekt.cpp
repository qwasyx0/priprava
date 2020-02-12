#pragma once
#include "Objekt.h"
#include "StatickyObjekt.h"

StatickyObjekt::StatickyObjekt(int id, TypPrekazky typPrekazky) : Objekt(id)
{
	this->typPrekazky = typPrekazky;
}

TypPrekazky StatickyObjekt::getTypPrekazky()
{
	return typPrekazky;
}
