#include <iostream>
#include "Objekt.h"
#include "StatickyObjekt.h"
#include "PohyblivyObjekt.h"
using namespace std;

int main()
{
	Objekt* objekt = new StatickyObjekt{ 1, TypPrekazky::MalaRostlina };
	StatickyObjekt* so = dynamic_cast<StatickyObjekt*>(objekt);
	if (so != nullptr) {
		cout << "objekt je StatickyObjekt(nebo jeho potomek)" << so->getTypPrekazky();	}

	Objekt* obj = new PohyblivyObjekt{2, 1};
	PohyblivyObjekt* po = dynamic_cast<PohyblivyObjekt*>(obj);
	if (po != nullptr) {
		cout << "objekt je PohyblivyObjekt(nebo jeho potomek)" << po->getUhelNatoceni();	}
}
