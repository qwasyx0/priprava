// cpp_cv8.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include "pch.h"
//#include <iostream>
//#include<fstream>
//#include<string>
//using namespace std;
/*
struct KomplexniCislo {
	double real;
	double img;

	KomplexniCislo() :real(0),img(0){}
	KomplexniCislo(double re,double im):real(re), img(im){}
};
ostream& operator<<(ostream& os, const KomplexniCislo& kc) { // PRETIYENY OPERATOR ------> TO CO SE PAK VYPISUJE JINAK BY TO BYLI NESMYSLI
	os << kc.real << " ";
	os << (kc.img >= 0 ? "+" : "-") << " ";
	os << abs(kc.img) << "i";
	return os;
}

istream& operator>>(istream& is, KomplexniCislo& kc) {
	is >> kc.real;
	char oper;
	is >> oper;
	is >> kc.img;
	if (oper == '-')
	{
		kc.img = -kc.img;

	}
	char imaginarniJednotka;
	is >> imaginarniJednotka;
	return is;
}

int main()
{
	cout << "Soubor " << endl;
	cout << " " << endl;

	ofstream vystup{ "soubor.txt" };
	for (int i = 0; i < 50; i++)
	{
		KomplexniCislo kc{ (double)(rand() % 50 - 100),(double)(rand() % 50 - 100) };
		vystup << kc << endl;

	}
	vystup.close();
	ifstream vstup{ "soubor.txt" };
	while (true)
	{
		KomplexniCislo kc{};
		vstup >> kc;
		if (vstup.eof() || vstup.fail()) {
			break;
		}
		cout << "Nacteno: " << kc << endl;
	}
	vstup.close();
	//string str{};
	//getline(vstup, str);
	return 0;

	cout << "To druhe " << endl;
	cout << " " << endl;

	KomplexniCislo kc{ 1,4 };
	cout << kc << endl;
	KomplexniCislo kc2{ -11,-27 };
	cout << kc2 << endl;
	cin >> kc;
	cout << "Nacteno: " << kc << endl;
    std::cout << "Hello World!\n"; 
	
}
*/
// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
