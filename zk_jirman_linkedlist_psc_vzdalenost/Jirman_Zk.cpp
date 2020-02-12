// Jirman_Zk.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "SmerovyAdresar.h"
#include <string>
#include <iostream>

using namespace std;
int main()
{

	SmerovyAdresar sm;

	string pscMin="", pscMax="";

	sm.vloz("Boleslav", "55203", "Trdla");
	sm.vloz("Boleslav", "55203", "Obrtla");
	sm.vloz("Boleslav", "55204", "Vinna");
	sm.vloz("Boleslav", "55204", "Trnkova");
	sm.vloz("Boleslav", "55206", "Hlinna");

	sm.vloz("Karlov", "123456", "Seda");
	sm.vloz("Karlov", "123457", "Cervena");

	sm.vloz("Medak", "35366", "Ruzova");

	
	sm.vypis();
	if (sm.najdiRozsahPsc("Boleslav", pscMin, pscMax))
		cout << "PSCmin: " << pscMin << ", PSCmax: " << pscMax << endl;
	else
		cout << "Mesto bud neexistuje nebo nema PSC";
	cout << "\n";

	if (sm.najdiRozsahPsc("Medak", pscMin, pscMax))
		cout << "PSCmin: " << pscMin << ", PSCmax: " << pscMax << endl;
	else
		cout << "Mesto bud neexistuje nebo nema PSC";
	cout << "\n";


	if (sm.najdiRozsahPsc("Neco", pscMin, pscMax))
		cout << "PSCmin: " << pscMin << ", PSCmax: " << pscMax << endl;
	else
		cout << "Mesto neexistuje nebo nema PSC";
	cout << "\n";

	cout << "\n";
	system("pause");
    return 0;
}

