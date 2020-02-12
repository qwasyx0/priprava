#pragma once
#include "PohyblivyObjekt.h"

struct Monstrum : PohyblivyObjekt {
public:
	void setHp(int);
	void setMaxhp(int);
	int getHp()const;
	int getMaxhp()const;
private:
	int hp;
	int maxhp;
};
