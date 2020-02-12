#pragma once

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "SpojovySeznam.h"
using namespace std;



struct SmerovyAdresar {
private:
	SpojovySeznam mesta;

public:
	void vloz(const string mesto, const string psc, const string ulice);

	bool najdiRozsahPsc(const string mesto, string& pscmin, string& pscmax);

	void vypis();

	

};