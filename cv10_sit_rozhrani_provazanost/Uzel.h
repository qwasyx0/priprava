#pragma once
#ifndef UZEL_H
#define UZEL_H
#include "ASitovyPrvek.h"
struct Uzel :ASitovyPrvek {
private:
	string adresa;
	ASitovyPrvek* pripojenyPrvek;
	Fronta <Zprava*> odchoziZpravy;

public:
	void Pripoj(ASitovyPrvek* sitovyPrvek) override;
	void Provadej() override;
	void ZpracujPrichoziZpravu(ZpravaPort zp) override;
	void PripravZpravuKOdeslani(string cil, string obsah);
};

#endif UZEL_H