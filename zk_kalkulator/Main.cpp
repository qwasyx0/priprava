#include "Kalkulator.h"
#include <iostream>
#include "VyjimkaKalkulator.h"




int main() {
	Kalkulator<double, 3> kalkulator{};

	kalkulator.pridejHodnotu(1.22);
	kalkulator.pridejOperator('+');
	kalkulator.pridejHodnotu(2.0);
	kalkulator.pridejOperator('*');
	kalkulator.pridejHodnotu(4.0);
	kalkulator.pridejOperator('/');
	kalkulator.pridejHodnotu(6.0);
	kalkulator.pridejOperator('-');
	kalkulator.pridejHodnotu(0.11);

	try
	{
		std::cout << kalkulator.vypocitej() << std::endl;
	}
	catch (const VyjimkaKalkulator&)
	{
		std::cout << VyjimkaKalkulator::dejText() << std::endl;
	}
	

	system("pause");
	return 0;
}