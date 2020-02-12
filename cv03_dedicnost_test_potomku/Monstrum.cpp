#include "Monstrum.h"

void Monstrum::setHp(int hp)
{
	this->hp = hp;
}

void Monstrum::setMaxhp(int maxhp)
{
	this->maxhp = maxhp;
}

int Monstrum::getHp()const
{
	return hp;
}

int Monstrum::getMaxhp()const
{
	return maxhp;
}
