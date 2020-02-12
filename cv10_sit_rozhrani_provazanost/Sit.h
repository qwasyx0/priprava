#pragma once
#ifndef SIT_H
#define SIT_H
#include "ASitovyPrvek.h"
#include "Fronta.h"

struct Sit {
private:
	static int idZpravy;
	Fronta<ASitovyPrvek *> sitovePrvky;
public:
	int DejNoveId();
	void Pripoj(ASitovyPrvek* sitovyPrvek);
	void ProvadejVse();
};

#endif //!SIT_H