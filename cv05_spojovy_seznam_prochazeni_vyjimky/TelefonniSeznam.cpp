#include "TelefonniSeznam.h"
#include <stdexcept>
#include <iostream>
using namespace std;

void navstiv(Entity::Osoba data, string jmeno) {
	if (data.getJmeno == jmeno) {

	}
}
Model::TelefonniSeznam::TelefonniSeznam()
{
	_zacatek = nullptr;
}

Model::TelefonniSeznam::~TelefonniSeznam()
{
	Entity::Osoba::PrvekSeznamu* prvekSeznamu = _zacatek;
	while (prvekSeznamu != nullptr) {
		Entity::Osoba::PrvekSeznamu* tmp = prvekSeznamu->dalsi;
		delete prvekSeznamu;
		prvekSeznamu = tmp;
	}
}

void Model::TelefonniSeznam::pridejOsobu(Entity::Osoba o)
{
	Entity::Osoba::PrvekSeznamu* novyPrvekSeznamu = new Entity::Osoba::PrvekSeznamu(o);
	novyPrvekSeznamu->dalsi = _zacatek;
	_zacatek = novyPrvekSeznamu;

}

std::string Model::TelefonniSeznam::najdiTelefon(string jmeno) const
{
	Entity::Osoba::PrvekSeznamu* prvekSeznamu = _zacatek;
	if (jmeno.size > 0) {
			while (prvekSeznamu != nullptr) {
				string navrat = prvekSeznamu->data.getJmeno();
				if (navrat == jmeno) {
					return prvekSeznamu->data.getTelefon();
				}
				prvekSeznamu = prvekSeznamu->dalsi;
			}		
		throw "Osoba nenalezena";
	} else {
		throw std::invalid_argument("Velikost jmena musi byt alespon 1.");
	}
}

std::string Model::TelefonniSeznam::najdiTelefon(int id) const
{
	Entity::Osoba::PrvekSeznamu* prvekSeznamu = _zacatek;
	if (id < 0) {
			while (prvekSeznamu != nullptr) {
				int navrat = prvekSeznamu->data.getId();
				if (navrat == id) {
					return prvekSeznamu->data.getTelefon();
				}
				prvekSeznamu = prvekSeznamu->dalsi;
			}		
			throw "Osoba nenalezena";
	}
	else {
		throw std::invalid_argument("Velikost jmena musi byt alespon 1.");
	}
}
