#include"pch.h"
#include<iostream>
#include<fstream>
#include "Osoba.h"
using namespace std;

struct KomplexniCislo
{
	double realna;
	char znak;
	double imaginarni;
	string str;

};

int main() {
	{
		KomplexniCislo kc[] = {
			{0,'H',0,"alfa"},{1,'H',0,"beta"},{0,'H',1,"gamma"}, {3.141592,'H',1,"a tady bude problem"}
		};
		ofstream f{ "komplexni.dat",ios_base::out | ios_base::binary };
		for (int i = 0; i < sizeof kc/sizeof kc[i]; i++)
		{
			//char znakz[100];
			int delka = 123;
			f.write((char*)&delka, sizeof (int));

			f.write((char*)&kc[i], sizeof kc[i]);
			string s{};
			const char* cstr = s.c_str();

		}
		f.close();
		{int pocet = 4;
		KomplexniCislo* kc = new KomplexniCislo[pocet];
		ifstream f{ "komplexni.dat",ios_base::in | ios_base::binary };
		for (int i = 0; i < pocet; i++)
		{
			f.read((char*)&kc[i], sizeof(KomplexniCislo));
		}
		f.close();
		for (int i = 0; i < pocet; i++)
		{
			cout << kc[i].realna << " + " << kc[i].imaginarni << "i ";
			cout << kc[i].znak << " ";
			cout << endl;
		}
		}
	}
	return 0;
}