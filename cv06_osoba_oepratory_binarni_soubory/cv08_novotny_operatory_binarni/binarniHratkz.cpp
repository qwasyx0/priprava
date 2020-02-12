#include "pch.h"
#include <iostream>
#include<fstream>
#include<string>

#include "Adresa.h"
#include"Datum.h"
#include"Osoba.h"

using namespace std;

int main() {
	//int pomoc=0;
	osoba pole[3];
	adresa adresaAdam{ "Ulice Nekde","Praha",19200 };
	datum datumAdam{ 5,10,1982 };
	osoba adam{ "Adam","Pokus",adresaAdam, datumAdam };
	//pomoc++;
	adresa adresaAdam2{ "Ulice Nekde2","Praha 2",192002 };
	datum datumAdam2{ 25,11,1984 };
	osoba adam2{ "Adam2","Pokus2",adresaAdam2, datumAdam2 };
	//pomoc++;
	adresa adresaAdam3{ "Ulice Nekde3","Praha3",192003 };
	datum datumAdam3{ 28,12,1986 };
	osoba adam3{ "Adam","Pokus",adresaAdam3, datumAdam3 };
	//pomoc++;
	pole[0] = adam;
	pole[1] = adam2;
	pole[2] = adam3;
	ofstream f{ "lide.dat",ios_base::out | ios_base::binary };
	for (int i = 0; i < sizeof pole / sizeof pole[i]; i++)
	{
		//char znakz[100];
		int delkaJmeno = 0;
		int delkaJmena = pole[i]._jmeno.size();
		int delkaPrijmeni = pole[i]._prijmeni.size();
		int delkaAdresaMesto = pole[i]._trvaleBydliste._mesto.size();
		int delkaAdresaUlice = pole[i]._trvaleBydliste._ulice.size();
		//cout << delkaJmena<<"   "<<delkaPrijmeni<<"   "<<delkaAdresa<<"    ";
		//cout << endl;
		f.write((char*)&delkaJmena, sizeof(int));
		f.write((char*)&delkaPrijmeni, sizeof(int));
		f.write((char*)&delkaAdresaMesto, sizeof(int));
		f.write((char*)&delkaAdresaUlice, sizeof(int));
		f.write(pole[i]._jmeno.c_str(),delkaJmeno);
		f.write(pole[i]._prijmeni.c_str(), delkaPrijmeni);
		f.write(pole[i]._trvaleBydliste._mesto.c_str(), delkaAdresaMesto);
		f.write(pole[i]._trvaleBydliste._ulice.c_str(), delkaAdresaUlice);
		//string s{};
		//const char* cstr = s.c_str();

	}
	f.close();
	/*
	{int pocet = 4;
	osoba* oso = new osoba[pocet];
	ifstream f{ "life.dat",ios_base::in | ios_base::binary };
	for (int i = 0; i < pocet; i++)
	{
		f.read((char*)&oso[i], sizeof(osoba));
	}
	f.close();
	for (int i = 0; i < pocet; i++)
	{
		cout << oso[i]._jmeno << ", " << oso[i]._prijmeni << ", " << oso[i]._datumNarozeni << ", " << oso[i]._trvaleBydliste;
		cout << endl;
	}
	*/
	return 0;
}