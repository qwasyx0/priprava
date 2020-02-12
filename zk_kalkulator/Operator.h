#pragma once
#include "PrvekVyrazu.h"
#include "EnumOperatory.h"
#include "VyjimkaKalkulator.h"

class Operator : public PrvekVyrazu
{
private:
	EnumOperatory _operator;
public:
	Operator();
	Operator(char znakOperatoru);
	EnumOperatory dejDruhOperatoru();
	~Operator();
};

