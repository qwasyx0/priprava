#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

enum Krmivo { SENO, GRANULE, ZELENINA };

class Krmelec {
private:
	int kusuSena = 0, kusuGranuli = 0, kusuZeleniny = 0;
public:
	Krmelec() {

	}
	void dosypej(Krmivo k, int kolik) {
		if (k == Krmivo::GRANULE) {
			kusuGranuli += kolik;
		}
		if (k == Krmivo::SENO) {
			kusuSena += kolik;
		}
		if (k == Krmivo::ZELENINA) {
			kusuZeleniny += kolik;
		}
	}
	bool sezer(Krmivo k, int kolik) {
		if (k == Krmivo::GRANULE) {
			if ((kusuGranuli - kolik) > 0) {
				kusuGranuli -= kolik;
				return true;
			}
			else
			{
				return false;
			}
		}
		if (k == Krmivo::SENO) {
			if ((kusuSena - kolik) > 0) {
				kusuSena -= kolik;
				return true;
			}
			else
			{
				return false;
			}
		}
		if (k == Krmivo::ZELENINA) {
			if ((kusuZeleniny - kolik) > 0) {
				kusuZeleniny -= kolik;
				return true;
			}
			else
			{
				return false;
			}
		}
	}
};


class Zvire {
protected:
	int energie = 10;
public:
	bool zije() {}
	virtual void nakrmit(Krmelec& k) = 0;
	virtual void vydejZvuk() = 0;

};

class Kralik :Zvire {
public:
	Kralik() :Zvire() {

	}
	virtual void nakrmit(Krmelec & k) override
	{
		k.dosypej(Krmivo::SENO, 10);
	}
	virtual void vydejZvuk() override
	{
		cout << "bzzzz";
		energie -= 2;
	}
	bool zije() {
		if (energie <= 0) {
			return false;
		}
		else {
			return true;
		}
	}
	int getEnergie() {
		cout << energie;
		return energie;

	}
};

int main() {
	Krmelec *k = new Krmelec();
	Kralik *kralik = new Kralik();
	kralik->zije();
	kralik->getEnergie();
	kralik->vydejZvuk();
	kralik->vydejZvuk();

	kralik->vydejZvuk();
	kralik->getEnergie();




	system("pause");
	return 0;
}