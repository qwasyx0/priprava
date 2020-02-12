#pragma once
#ifndef __STROM_H
#define __STROM_H

#include <string>
using namespace std;

struct Strom {
private:
	int vek;
	string druh;
	int* cislo;

public:
	Strom();
	Strom(int vek); //konstruktor
	~Strom(); //destruktor

	void setVek(int v);

protected:

};
#endif