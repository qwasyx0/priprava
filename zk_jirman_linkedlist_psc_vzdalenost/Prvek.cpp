#include "stdafx.h"
#include "Prvek.h"
#include "SpojovySeznam.h"
using namespace std;

Prvek::Prvek()
{
}

Prvek::Prvek(string klic) 
{
	
	this->klic = klic;
	this->dalsi = nullptr;
	
	
	
}


