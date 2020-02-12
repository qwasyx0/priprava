#include "strom.h"

Strom::Strom() {
	this->vek = 0;
	this->cislo = new int{ 99 };
}
Strom::Strom(int vek) {
	this->vek = vek;
	this->cislo = new int{ 99 };
}
Strom::~Strom() {
	delete this->cislo;
}
void Strom::setVek(int v) {
	vek = v;
	//this->vek = v;
	//(*this).vek = v;
	//this[0].vek = v;
}