#pragma once
#ifndef ASITOVYPRVEK_H
#define ASITOVYPRVEK_H
#include <string>
#include <iostream>
#include "Fronta.h"
#include "ZpravaPort.h"

using namespace std;

struct ASitovyPrvek {
public:
	Fronta<ZpravaPort> prichoziZpravy;	
	virtual void Provadej() = 0;
	virtual void Pripoj(ASitovyPrvek* sitovyPrvek) = 0;
	virtual void VlozPrichoziZpravu(Zprava* zprava, ASitovyPrvek* port);
	virtual void ZpracujPrichoziZpravu(ZpravaPort zp) = 0;
};
#endif //!ASITOVYPRVEK_H