#include <iostream>
#include "Adresa.h"
#include "Datum.h"
#include "Osoba.h"
#include <fstream>
#include <iostream>
using namespace std;


void uloz(Osoba* osoby) {
	ofstream out{};
	out.open("uloz.txt");

	if (out.is_open()) {
		out << "3" << endl;
		for (size_t i = 0; i < 3; i++)
		{
			out << osoby[i].toString() << endl;
		}
		out.close();
	}
	else {
		cerr << "Soubor se nepodarilo otevrit...";
	}
}


void nacti() {
	Osoba osoby[3];

	ifstream soubor{ "uloz.txt" };
	int pocet;
	soubor >> pocet;
	for (int i = 0; i < pocet; i++) 
	{
		soubor >> osoby[i];
	}
	for (int i = 0; i < pocet; i++)
	{
		cout << "Nacteno txt: " << osoby[i] << endl;
	}
	soubor.close();
}

//retezce postupne ukladat sam
void ulozStruktury(Osoba* osoby) {
	ofstream f{ "soubor.dat", ios_base::out | ios_base::binary };
	/*for (size_t i = 0; i < 3; i++)
	{
		f.write((char*)&osoby[i], sizeof Osoba);
	}
	f.seekp(48);*/
#define VELIKOST 100 //Pevna velikost nacitani bajtu
	for (size_t i = 0; i < 3; i++)
	{
		string s{ osoby[i].getJmeno()};
		s.resize(VELIKOST);
		f.write(s.c_str(), s.size());
		s = osoby[i].getPrijmeni() ;
		s.resize(VELIKOST);
		f.write(s.c_str(), s.size());
		Adresa adr = osoby[i].getAdresa();
		s = adr.getUlice() ;
		s.resize(VELIKOST);
		f.write(s.c_str(), s.size());
		s = adr.getMesto() ;
		s.resize(VELIKOST);
		f.write(s.c_str(), s.size());
		s=to_string(adr.getPsc());
		s.resize(VELIKOST);
		f.write(s.c_str(), s.size());
		Datum dat = osoby[i].getDatum();
		s = to_string(dat.getDen()) ;
		s.resize(VELIKOST);
		f.write(s.c_str(), s.size());
		s = to_string(dat.getMesic());
		s.resize(VELIKOST);
		f.write(s.c_str(), s.size());
		s = to_string(dat.getRok());
		s.resize(VELIKOST);
		f.write(s.c_str(), s.size());
	}
	f.close();
}

void nactiStrukturu() {
	ifstream f{ "soubor.dat", ios_base::in | ios_base::binary };
	/*f.seekg(48);
	char retezec[VELIKOST];
	for (size_t i = 0; i < 3; i++)
	{
		f.read(retezec, sizeof retezec);
		string s{ retezec, VELIKOST };
		cout << "Nacteno bin: " << s << endl;
	}*/
	Osoba* pole = new Osoba[3];
	char retezec[VELIKOST];
	for (size_t i = 0; i < 3; i++)
	{
		f.read(retezec, VELIKOST);
		pole[i].setJmeno(retezec);
		f.read(retezec, VELIKOST);
		pole[i].setPrijmeni(retezec);
		f.read(retezec, VELIKOST);
		Adresa adr{};
		adr.setUlice(retezec);
		f.read(retezec, VELIKOST);
		adr.setMesto(retezec);
		f.read(retezec, VELIKOST);
		adr.setPsc(stoi(retezec));
		pole[i].setAdresa(adr);
		f.read(retezec, VELIKOST);
		Datum dat{};
		dat.setDen(stoi(retezec));
		f.read(retezec, VELIKOST);
		dat.setMesic(stoi(retezec));
		f.read(retezec, VELIKOST);
		dat.setRok(stoi(retezec));
		pole[i].setDatum(dat);
	}
	/*
	f.seekg(0, ios_base::end);
	int velikost = f.tellg();
	f.seekg(0, ios_base::beg);

	int pocet = velikost / sizeof Osoba;
	Osoba* pole = new Osoba[3];
	for (size_t i = 0; i < pocet; i++)
	{
		f.read((char*)&pole[i], sizeof Osoba);
	}*/
	for (size_t i = 0; i < 3; i++)
	{
		cout << "Nacteno bin: " << pole[i].toString() <<endl;
	}
	f.close();
}

int main()
{
	Osoba osoby[3];
	Datum datum1{ 1, 2, 3 };
	Datum datum2{ 20, 2, 1995 };
	Datum datum3{ 18, 11, 2009 };
	Adresa adresa1{ "studentska", "pardubice", 55001 };
	Adresa adresa2{ "petrohrad", "praha", 84759 };
	Adresa adresa3{ "stadion", "nachod", 48596 };

	osoby[0].setJmeno("Filiprhtfjfhngvsrgtrxjzcgkmughmkzjtjnrtfnrtfrt");
	osoby[0].setPrijmeni("Pekanrtnrtnrtnrtnrtnrtsnbrtndrmzgtchunbsrtgbrfervereargternerbneravgaerbrtebrstnbsrtr");
	osoby[0].setDatum(datum1);
	osoby[0].setAdresa(adresa1);

	osoby[1].setJmeno("Martin");
	osoby[1].setPrijmeni("Dlouhy");
	osoby[1].setDatum(datum2);
	osoby[1].setAdresa(adresa2);

	osoby[2].setJmeno("Antonin");
	osoby[2].setPrijmeni("Dlouhy");
	osoby[2].setDatum(datum3);
	osoby[2].setAdresa(adresa3);
	cout << ("Vytvorene: ") << endl;
	for (size_t i = 0; i < 3; i++)
	{
		cout << osoby[i].toString() << endl;

	}
	uloz(osoby);
	nacti();
	ulozStruktury(osoby);
	nactiStrukturu();
}
