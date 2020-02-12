#include "Hub.h"

Hub::Hub(int maximumPripojenychPrvku)
{
	this->maximumPripojenychPrvku = maximumPripojenychPrvku;
	pripojenePrvky = new ASitovyPrvek*();
	for (int i = 0; i < maximumPripojenychPrvku; i++) {
		pripojenePrvky[i] = nullptr;	
	}
}

void Hub::Pripoj(ASitovyPrvek* sitovyPrvek)
{
	for (size_t i = 0; i < maximumPripojenychPrvku; i++)
	{
		if (pripojenePrvky[i] == nullptr) {
			pripojenePrvky[i] = sitovyPrvek;
			break; //zablokoval bych cele pole, muze se pouzit i return;
		}
	}
}

void Hub::Provadej()
{
	for (int i = 0; i < maximumPripojenychPrvku; i++) {
		pripojenePrvky[i]->ZpracujPrichoziZpravu(prichoziZpravy.Odeber());
	}
}

void Hub::ZpracujPrichoziZpravu(ZpravaPort zp)
{

	if (zpracovaneZpravy.Obsahuje(zp.zprava)) {
		return;
	} else {
		for (size_t i = 0; i < maximumPripojenychPrvku; i++)
		{
			if (pripojenePrvky[i] != nullptr) {
				if (pripojenePrvky[i] != zp.port) {
					pripojenePrvky[i]->VlozPrichoziZpravu(zp.zprava, zp.port);
					zpracovaneZpravy.Vloz(zp.zprava);
				}		
			}
		}
	}
}
