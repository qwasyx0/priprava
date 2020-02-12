#include "Sit.h"

int Sit::DejNoveId()
{
	return ++idZpravy;
}

void Sit::Pripoj(ASitovyPrvek* sitovyPrvek)
{
	if (!sitovePrvky.Obsahuje(sitovyPrvek)) {
		sitovePrvky.Vloz(sitovyPrvek);
	}
}

void Sit::ProvadejVse()
{
	
	//sitovePrvky.ZpracujPrvky();
}
