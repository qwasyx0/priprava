#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>


using namespace std;


enum TypZvirete {
	OVCE, KRALIK, PES
};

class  maloKralikuException : public std::exception {
public:
	virtual const char* what() const throw()
	{
		return "Pocet kraliku malem klesl do zaporu.";
	}
};

class mizejiciPesException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Pes nesmí zmizet!";
	}
};

class Ohradka {
public:
	int *pole = new int[3];

	int inkrementuj(TypZvirete tz) {
		if (tz == TypZvirete::KRALIK) {
			return pole[1] += 3;
		}
		if (tz == TypZvirete::OVCE) {
			return pole[0]++;
		}

		if (tz == TypZvirete::PES) {
			return pole[2]++;
		}
		return 0;
	}

	int dekrementuj(TypZvirete tz) {
		if (tz == TypZvirete::KRALIK) {
			int randomCislo = rand() % 1;
			if (randomCislo == 0) {
				if ((pole[1] - 2) < 0) {
					throw maloKralikuException();

				}
				else {
					return pole[1] -= 2;
				}
				if ((pole[1] - 4) < 0) {
					throw maloKralikuException();
				}
			}
			else {
				return	pole[1] -= 4;
			}
		}

		if (tz == TypZvirete::OVCE) {
			pole[0]--;
			return pole[0];
		}
		if (tz == TypZvirete::PES) {
			throw mizejiciPesException();
		}
	}

	Ohradka(int pocetOvci, int pocetKraliku, int pocetPsu) {
		pole[0] = pocetOvci;
		pole[1] = pocetKraliku;
		pole[2] = pocetPsu;
	}

	~Ohradka() {
		delete[] pole;
	}


};


class Zvire {
public:
	virtual void vstupDoOhradky(Ohradka &ohradka) = 0;
	virtual void vystupZOhradky(Ohradka &ohradka) = 0;

protected:
	string druh;


public:
	string getDruh() {
		return druh;
	}

	Zvire(string _druh) {
	}
};

class Ovce :public Zvire {
public:
	Ovce() :Zvire("Ovce") {}
	virtual void vstupDoOhradky(Ohradka & ohradka) override
	{
		cout << "soucastny pocet ovci " << ohradka.pole[0] << "\n";
		ohradka.inkrementuj(OVCE);
		cout << "soucastny pocet ovci po pridani " << ohradka.pole[0] << "\n";
	}
	virtual void vystupZOhradky(Ohradka & ohradka) override
	{
		cout << "soucastny pocet ovci " << ohradka.pole[0] << "\n";
		ohradka.dekrementuj(OVCE);
		cout << "soucastny pocet ovci po odebrani " << ohradka.pole[0] << "\n";
	}
};

class Pes :Zvire {
public:
	Pes() : Zvire("Pes") {}
	virtual void vstupDoOhradky(Ohradka & ohradka) override
	{
		cout << "soucastny pocet psu " << ohradka.pole[2] << "\n";
		ohradka.inkrementuj(PES);
		cout << "soucastny pocet psu po pridani " << ohradka.pole[2] << "\n";
	}
	virtual void vystupZOhradky(Ohradka & ohradka) override
	{
		throw mizejiciPesException();
	}
};

class Kralik :Zvire {
public:
	Kralik() :Zvire("Kralik") {}
	virtual void vstupDoOhradky(Ohradka & ohradka) override
	{
		cout << "soucastny pocet kraliku " << ohradka.pole[1] << "\n";
		ohradka.inkrementuj(KRALIK);
		cout << "soucastny pocet kraliku po pridani " << ohradka.pole[1] << "\n";
	}
	virtual void vystupZOhradky(Ohradka & ohradka) override
	{
		cout << "soucastny pocet kraliku " << ohradka.pole[1] << "\n";
		ohradka.dekrementuj(KRALIK);
		cout << "soucastny pocet kraliku po odebrani " << ohradka.pole[1] << "\n";
	}
};

int main() {
	Ohradka *o = new Ohradka(3, 17, 1);


	for (size_t i = 0; i < 30; i++)
	{


		int randomCislo = rand() % 3;
		//	cout << randomCislo;
		if (randomCislo == 0) {
			Ovce *ovce = new Ovce();
			ovce->vstupDoOhradky(*o);
			ovce->vystupZOhradky(*o);


		}
		if (randomCislo == 1) {
			Kralik *k = new Kralik();
			k->vstupDoOhradky(*o);
			k->vystupZOhradky(*o);
		}
		if (randomCislo == 2) {
			Pes *p = new Pes();
			p->vstupDoOhradky(*o);
			p->vystupZOhradky(*o);
		}
	}

	system("pause");
	return 0;
}
