#include <iostream>
#include "uctenka.h"
#include "pokladna.h"

using namespace std;

struct A {

};
struct B {
	B(A& a) {
		//this->a = a;
	}
private:

};

int main()
{
	A a{};
	B b{a};
	/*
		//Strom prvniStromg; //vytvori rovnou nejaky objekt, dealokace automaticky kompilatorem
		Strom druhyStrom{}; //to same, ale inicializovany (volani kontruktoru strom) - pouzivat tento
		//Strom tretiStrom = Strom();  //nepreferovany zapis
		//Strom ctvrtyStrom = Strom{}; //nepreferovany zapis

		Strom* patyStrom = new Strom{}; //musi se pouzit delete potom
		//Strom* sestyStrom = new Strom; //ukazatel na Heap, pouzit delete
		Strom* prvniLes = new Strom[10]; //pouzit delete[]. vytvari se objekt
		Strom** lesLesu = new Strom * [10]; //nevytvari se objekt

		//Strom nutlyStrom(); //prototyp funkce, nebude fungovat i kdyz jde zkompilovat
		//Strom prvniParametrickyStrom(12);
		Strom druhyParametrickyStrom{ 12 }; //varianta C++11
		//Strom tretiParamatrickyStrom = Strom(12);
		//Strom ctvrtyParametrickyStrom = Strom{ 12 };
		Strom* patyParametrickyStrom = new Strom{ 12 };
		//Strom* sestyParametrickyStrom = new Strom(12);

		druhyStrom.setVek(10);
		/*
		druhyStrom.druh = "kastan";
		druhyStrom.setVek(1);

		(*patyStrom).vek = 2;
		patyStrom->druh = "briza";

		prvniLes[0].vek = 1;
		(*(prvniLes + 1)).vek = 2;
		(*(&(*(&prvniLes[2])))).vek = 3;

		lesLesu[0] = new Strom{};
		lesLesu[0]->vek = 99;
		delete lesLesu[0];
		*//*
		delete patyStrom;
		delete patyParametrickyStrom;
		delete[] prvniLes;
		delete[] lesLesu;
		
		return 0;
	
	*/
	Pokladna pokladna{};
	Uctenka& u = pokladna.vystavUctenku(200, 0.2);
	cout << u.getCastka() << " " << u.getDph() << " " << u.getCisloUctenky() << endl;

	u.setCisloUctenky(123);

	const Uctenka uu = pokladna.dejUctenku(123);
	cout << uu.getCastka() << " " << uu.getDph() << " " << uu.getCisloUctenky() << endl;
	//uu.setCisloUctenky(100); //settery nejdou pri const

	//toto nikdy nedelat
	/*Uctenka& odebraniConst = const_cast<Uctenka&>(uu);
	odebraniConst.setCisloUctenky(100); //ale uz bude fungovat

	const char* ptr = "Hello World";
	char * mptr = const_cast<char*>(ptr);
	*mptr = '0';*/

	return 0;
}
