#pragma once
#include "PrvekVyrazu.h"
#include "Operator.h"
#include "Hodnota.h"
#include "VyjimkaKalkulator.h"
#include "DynAlokPole.h"
#include "EnumOperatory.h"

template<typename Data, int zaokrouhleni>
class Kalkulator
{
private:

	DynAlokPole<PrvekVyrazu*> _polePrvku{};

public:
	Kalkulator();
	void pridejHodnotu(const Data& hodnota);
	void pridejOperator(const char& charOperator);
	Data vypocitej();

	~Kalkulator();
};

template<typename Data, int zaokrouhleni>
inline Kalkulator<Data, zaokrouhleni>::Kalkulator()
{
}

template<typename Data, int zaokrouhleni>
void Kalkulator<Data, zaokrouhleni>::pridejHodnotu(const Data & hodnota)
{
	Hodnota<Data>* hod = new Hodnota<Data>(hodnota);
	_polePrvku.pridejPrvek(hod);
}

template<typename Data, int zaokrouhleni>
void Kalkulator<Data, zaokrouhleni>::pridejOperator(const char & charOperator)
{
	Operator* op = new Operator(charOperator);
	if (op->dejDruhOperatoru() == EnumOperatory::NEDEFINOVATELNY)
	{
		delete op;
		throw VyjimkaKalkulator();
	}
	else {
		_polePrvku.pridejPrvek(op);
	}

}

template<typename Data, int zaokrouhleni>
Data Kalkulator<Data, zaokrouhleni>::vypocitej()
{

	//prvni hodnota, ovìøení, zda je první PrvekVyrazu Hodnotou
	if (_polePrvku.dejPocetPrvku() == 0 || _polePrvku.dejPrvekNaPozici(0)->dejDruhPrvku() == EnumDruhPrvku::OPERATOR)
	{
		throw VyjimkaKalkulator();
	}
	Data vysledek = ((Hodnota<Data>*)_polePrvku.dejPrvekNaPozici(0))->dejHodnotu();

	for (int i = 1; i < _polePrvku.dejPocetPrvku(); i++)
	{
		//nesaháme mimo pole a prvky po sobì logicky následují tak, jak mají
		if ((i + 1) >= _polePrvku.dejPocetPrvku() || _polePrvku.dejPrvekNaPozici(i)->dejDruhPrvku() == EnumDruhPrvku::HODNOTA || _polePrvku.dejPrvekNaPozici(i + 1)->dejDruhPrvku() == EnumDruhPrvku::OPERATOR)
		{
			throw VyjimkaKalkulator();
		}

		Operator* op = ((Operator*)_polePrvku.dejPrvekNaPozici(i));
		i++;
		Hodnota<Data>* ho = ((Hodnota<Data>*)_polePrvku.dejPrvekNaPozici(i));

		switch (op->dejDruhOperatoru())
		{
		case EnumOperatory::PLUS:
			vysledek += ho->dejHodnotu();
			break;
		case EnumOperatory::MINUS:
			vysledek -= ho->dejHodnotu();
			break;
		case EnumOperatory::KRAT:
			vysledek *= ho->dejHodnotu();
			break;
		case EnumOperatory::DELENO:
			vysledek /= ho->dejHodnotu();
			break;
		default:
			throw VyjimkaKalkulator();
		}
	}

	return (Data)(roundf(vysledek * pow(10.0, zaokrouhleni)) / pow(10.0, zaokrouhleni));
}

template<typename Data, int zaokrouhleni>
Kalkulator<Data, zaokrouhleni>::~Kalkulator()
{
	for (int i = 0; i < _polePrvku.dejPocetPrvku(); i++)
	{
		delete _polePrvku.dejPrvekNaPozici(i);
	}

}
