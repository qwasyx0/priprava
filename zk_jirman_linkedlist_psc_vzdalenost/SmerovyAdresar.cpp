#include "stdafx.h"
#include "SmerovyAdresar.h"
#include <string>
#include "Prvek.h"
#include "TypExtremu.h"
using namespace std;


void SmerovyAdresar::vloz(const string mesto, const string psc, const string ulice)
{
	Prvek * mest;
	Prvek* ps;
	Prvek* ul;
	mest=mesta.najdiNeboVloz(mesto);
	ps=mest->data.najdiNeboVloz(psc);
	ul = ps->data.najdiNeboVloz(ulice);
}

bool SmerovyAdresar::najdiRozsahPsc(const string mesto, string & pscmin, string & pscmax)
{
	Prvek *mst;
	mst=mesta.najdi(mesto);
	if (mst == nullptr)
		return false;
	else {

		if (mst->data.jePrazdny())
			return false;
		else {
			pscmin = mst->data.najdiExtrem(Minimum)->klic;
			pscmax = mst->data.najdiExtrem(Maximum)->klic;
			return true;
		}
	}

}

void SmerovyAdresar::vypis()
{
	mesta.vypis();
}


