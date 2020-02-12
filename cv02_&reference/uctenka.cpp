#include"uctenka.h"
#include<iostream>


void Uctenka::setCisloUctenky(int cisloUctenky){
	this->cisloUctenky = cisloUctenky;
}

int Uctenka::getCisloUctenky()
{
	cisloUctenky++;
	return cisloUctenky;
}

int Uctenka::getCisloUctenky() const{
	return cisloUctenky;
}

void Uctenka::setCastka(double castka) {
	this->castka = castka;
}

double Uctenka::getCastka() const {
	return castka;
}

void Uctenka::setDph(double dph) {
	this->dph = dph;
}

double Uctenka::getDph() const{
	return dph;
}

