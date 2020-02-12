#include "stdafx.h"
#include "SpojovySeznam.h"
#include "Prvek.h"
#include <string>
#include <iostream>


using namespace std;

SpojovySeznam::SpojovySeznam()
{
	prvni = nullptr;

}

Prvek * SpojovySeznam::vloz(const string klic)
{
	if (prvni == nullptr) {
		prvni = new Prvek(klic);
	}
	else
	{
		Prvek* zal;
		zal = prvni;
		prvni = new Prvek(klic);
		prvni->dalsi = zal;
	}
		return prvni;
}

Prvek * SpojovySeznam::najdi(const string klic)
{

	Prvek* pom=prvni;
	
	while (pom != nullptr) {
		if (klic.compare(pom->klic) == 0) {
			return pom;
		}
		pom = pom->dalsi;
	}
	return nullptr;
}

Prvek * SpojovySeznam::najdiNeboVloz(const string klic)
{
	if (najdi(klic) != nullptr) {
		return najdi(klic);
	}
	else
	{
		return vloz(klic);

	}
}

Prvek * SpojovySeznam::najdiExtrem(const TypExtremu te)
{
	string vrat;
	Prvek* pom = prvni;
	Prvek* vratP = prvni;
	vrat = prvni->klic;
	
	if (jePrazdny())
		return nullptr;

	while (pom != nullptr) {
		if (te == Maximum) {
			if (vrat.compare(pom->klic)<0) {
				vrat = pom->klic;
				vratP = pom;
			}
		}
		else {
			if (vrat.compare(pom->klic)>0) {
				vrat = pom->klic;
				vratP = pom;
			}
		}

		pom = pom->dalsi;
	}
	return vratP;
}

bool SpojovySeznam::jePrazdny()
{
	if (prvni == nullptr)
		return true;
	else
		return false;
}

void SpojovySeznam::vypis(int odsazeni)
{
	Prvek* pom = prvni;
	string mezery="";
	for (size_t i = 0; i < odsazeni; i++)
	{
		mezery = mezery + " ";
	}

	while (pom != nullptr) {
		
		cout << mezery << pom->klic ;
		pom->data.vypis(odsazeni + 2);
		pom = pom->dalsi;
		if (odsazeni == 0)
		cout << "\n";
	}

	

}

SpojovySeznam::~SpojovySeznam()
{
	Prvek* pom;
	while (prvni != nullptr) {
		pom = prvni->dalsi;
		delete prvni;
		prvni = pom;

	}
	delete prvni;
}



