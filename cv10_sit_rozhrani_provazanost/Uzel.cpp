#include "Uzel.h"

void Uzel::Pripoj(ASitovyPrvek* sitovyPrvek) {
	pripojenyPrvek->Pripoj(sitovyPrvek);
}

void Uzel::Provadej()
{
	Zprava* zprava = odchoziZpravy.Odeber();

	//pripojenyPrvek->ZpracujPrichoziZpravu();
}

void Uzel::ZpracujPrichoziZpravu(ZpravaPort zp)
{
	if (zp.port == pripojenyPrvek) {
		return;
	} else{
		if(zp.zprava->obsah == "ping")
		cout << zp.zprava->adrCil<<  " " << zp.zprava->adrZdroj<< " id:" << zp.zprava->id << " msg:" << zp.zprava->obsah << endl;
	}
}

void Uzel::PripravZpravuKOdeslani(string cil, string obsah)
{
}
