#include "Osoba.h"
#include <iostream>
#include <string>
using namespace std;

Entity::Osoba::Osoba(string jmeno, string telefon, int id) : jmeno(jmeno) //a ty 2 taky sem
{
	this->jmeno = jmeno;
	this->telefon = telefon;
	this->id = id;
}

Entity::Osoba::~Osoba()
{
}

void Entity::Osoba::setJmeno(string jm)
{
	jmeno = jm;
}

void Entity::Osoba::setTelefon(string tel)
{
	telefon = tel;
}

void Entity::Osoba::setId(int id)
{
	this->id = id;
}

string Entity::Osoba::getJmeno() const
{
	return jmeno;
}

string Entity::Osoba::getTelefon() const
{
	return telefon;
}

int Entity::Osoba::getId() const
{
	return id;
}

Entity::Osoba::PrvekSeznamu::PrvekSeznamu(Entity::Osoba data)
{
	this->data = data;
}

Entity::Osoba::PrvekSeznamu::PrvekSeznamu()
{
}
