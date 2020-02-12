#pragma once
#ifndef ZPRAVA_H
#define ZPRAVA_H
#include <string>
#include <iostream>
struct ASitovyPrvek;

struct Zprava {
	int id;
	std::string adrZdroj;
	std::string adrCil;
	std::string obsah;
	Zprava() { }
	Zprava(int id, std::string adrZdroj, std::string adrCil, std::string obsah) : id(id), adrZdroj(adrZdroj), adrCil(adrCil), obsah(obsah) { }
};
#endif //!ZPRAVA_H