f// Zkouska412018Burda.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class pesVystupException : public exception
{
	public:
	const char* what() const throw() 
	{ 
		return "Pes nemmuze vystoupit z ohradky."; 
	}
};

class maloKralikuException : public exception
{
public:
	const char* what() const throw()
	{
		return "Pocet kraliku malem klesl do zaporu.";
	}
};

class Ohradka {
private:
	int poctyZviratek[3];	//ovce, pes, kralik
public:
	Ohradka() {};
	~Ohradka() {
		delete poctyZviratek;
	};

	int* getPoleZviratek() {
		return poctyZviratek;
	}
};

class Zvire {
private:
	string jmeno;
public:
	Zvire(string jmeno) {
		this->jmeno = jmeno;
	};
	
	string getJmeno() {
		return jmeno;
	}
	virtual void vstupDoOhradky(Ohradka& ohradka) = 0;
	virtual void vystupZOhradky(Ohradka& ohradka) = 0;
};

class Ovce : public Zvire {
public:
	Ovce(string jmeno) : Zvire(jmeno){}
	void vstupDoOhradky(Ohradka& ohradka) {
		int pocetOvci = ohradka.getPoleZviratek()[0];
		pocetOvci++;
		ohradka.getPoleZviratek()[0] = pocetOvci;
		cout << "Ovce " << getJmeno() <<" vstupuje do ohradky. Je zde "<< ohradka.getPoleZviratek()[0]<<" ovci." << endl;
		//cout << pocetOvci << endl;
	}
	void vystupZOhradky(Ohradka& ohradka) {
		int pocetOvci = ohradka.getPoleZviratek()[0];
		pocetOvci--;
		ohradka.getPoleZviratek()[0] = pocetOvci;
		cout << "Ovce " << getJmeno() << " vystupuje ze ohradky. Zbyva zde "<< ohradka.getPoleZviratek()[0]<<" ovci." << endl;
	}
};

class Pes : public Zvire {
public:
	Pes(string jmeno) : Zvire(jmeno) {}
	void vstupDoOhradky(Ohradka& ohradka) {
		int pocetPsu = ohradka.getPoleZviratek()[1];
		pocetPsu++;
		ohradka.getPoleZviratek()[1] = pocetPsu;
		cout << "Pes " << getJmeno() << " vstupuje do ohradky. Jiz je zde " << ohradka.getPoleZviratek()[1] << " psu." << endl;
		//ohradka.getPoleZviratek[1]++;
	}
	void vystupZOhradky(Ohradka& ohradka) {
		throw pesVystupException();
	}
};

class Kralik : public Zvire {
public:
	Kralik(string jmeno) : Zvire(jmeno) {}
	void vstupDoOhradky(Ohradka& ohradka) {
		int randomKralici = 3+(3 * (rand() / (RAND_MAX + 1.0)));
		int pocetKraliku = ohradka.getPoleZviratek()[2];
		pocetKraliku = pocetKraliku + randomKralici;
		ohradka.getPoleZviratek()[2] = pocetKraliku;
		cout << "Skupina " << randomKralici <<" kraliku vstupuje do ohradky. Jiz je zde " << ohradka.getPoleZviratek()[2] << " kraliku." << endl;
	}
	void vystupZOhradky(Ohradka& ohradka) {
		int randomKralici = 2 + (5 * (rand() / (RAND_MAX + 1.0)));
		int pocetKraliku = ohradka.getPoleZviratek()[2];
		pocetKraliku = pocetKraliku - randomKralici;
		if (pocetKraliku <= 0) {
			throw maloKralikuException();
			ohradka.getPoleZviratek()[2] = 0;
		}
		else {
			ohradka.getPoleZviratek()[2] = pocetKraliku;
		}
		cout << "Skupina " << randomKralici << " kraliku vystupuje z ohradky. Zbyva zde " << ohradka.getPoleZviratek()[2] << " kraliku." << endl;
	}
};



int main()
{
	Ohradka ohradka{};
	ohradka.getPoleZviratek()[0] = 3;
	ohradka.getPoleZviratek()[1] = 1;
	ohradka.getPoleZviratek()[2] = 17;

	string jmeno;

	//Ovce ovce{ jmeno };
	//ovce.vstupDoOhradky(ohradka);
	//ovce.vystupZOhradky(ohradka);

	//cout << ohradka.getPoleZviratek()[0] << endl;

	Zvire *zvire1;
	cout << "Ohradka pro snova zviratka: " << endl << endl;
	for (int i = 0; i < 30; i++) 
	{
		jmeno = "jmeno " + to_string(i+1);
		//cout << jmeno << endl;
		int random = 3 * (rand() / (RAND_MAX + 1.0));
		//cout << random << endl;
		if (random == 0) {
			Ovce zvire{ jmeno };
			zvire1 = &zvire;

		}
		else if (random == 1){
			Pes zvire{ jmeno };
			zvire1 = &zvire;
		}
		else {
			Kralik zvire{ jmeno };
			zvire1 = &zvire;
		}

		//vstup a výstup z ohrádky
		zvire1->vstupDoOhradky(ohradka);
		try{
			zvire1->vystupZOhradky(ohradka);
		}
		catch (pesVystupException &ex) {
			cout << ex.what() << endl;
		}
		catch (maloKralikuException &ex) {
			cout << ex.what() << endl;
		}
		
	}

	//system("Pause");
    return 0;
}

