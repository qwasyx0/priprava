#pragma once
#ifndef HUB_H
#define HUB_H

#include "ASitovyPrvek.h"
#include <iostream>
#include <string>

struct Hub : ASitovyPrvek{
private:
	ASitovyPrvek** pripojenePrvky;
	int maximumPripojenychPrvku;
	Fronta <Zprava*> zpracovaneZpravy;
public:
	Hub(int maximumPripojenychPrvku);
	void Pripoj(ASitovyPrvek* sitovyPrvek) override;
	void Provadej() override;
	void ZpracujPrichoziZpravu(ZpravaPort zp) override;
};
#endif //!HUB_H