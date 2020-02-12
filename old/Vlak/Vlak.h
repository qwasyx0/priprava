#include <iostream>
#include <string>

using namespace std;

class Vlak {
protected:
	string oznaceni;		
	char* casPrijezdu;
	char* casOdjezdu;
public:
	virtual void Prijezd() = 0;
	virtual void Odjezd() = 0;
	virtual void toString() = 0; 
	bool operator==(const Vlak &druhy) const;
	bool operator!=(const Vlak &druhy) const;
};

bool Vlak::operator==(const Vlak &druhy) const {
	if (oznaceni == druhy.oznaceni) {
		return true;
	} else {
		return false;}
}

bool Vlak::operator!=(const Vlak &druhy) const {
	if (oznaceni == druhy.oznaceni) {
		return false;
	} else {
		return true;}
}




class Osobni : public Vlak {
protected:
	int maxCestujicich;
public:
	void Prijezd() {cout << "Prijezd osobniho vlaku: " << casPrijezdu << endl;};
	void Odjezd() {cout << "Odjezd osobniho vlaku: " << casOdjezdu;};
	Osobni(string, int, char*, char*);
	void toString();
	Osobni* operator + (const Osobni &druhy) const;
};

Osobni::Osobni(string oznaceni, int maxCestujicich, char* casPrijezdu, char* casOdjezdu) {
	this->oznaceni = oznaceni;
	this->maxCestujicich = maxCestujicich;
	this->casPrijezdu = casPrijezdu;
	this->casOdjezdu = casOdjezdu;
}

void Osobni::toString() {
	cout << "Osobni vlak c.: " << oznaceni << ", max. pocet cestujicich: " << maxCestujicich << endl;
	Prijezd();
	Odjezd();
	cout << "\n-------------------------------------------------------------\n";
}

Osobni* Osobni::operator+ (const Osobni &druhy) const {

	Osobni* nova = new Osobni(this->oznaceni, (this->maxCestujicich>druhy.maxCestujicich? this->maxCestujicich : druhy.maxCestujicich), 
		(this->casPrijezdu<druhy.casPrijezdu?this->casPrijezdu:druhy.casPrijezdu),
		(this->casOdjezdu<druhy.casOdjezdu?this->casOdjezdu:druhy.casOdjezdu)
		);

	return nova;
	
};

class Rychlik : public Vlak {
protected:
	bool jeZapojen;
public:
	void Prijezd() {cout << "Prijezd rychliku: " << casPrijezdu << endl;};
	void Odjezd() {cout << "Odjezd rychliku: " << casOdjezdu;};
	Rychlik(string, bool, char*, char*);
	void toString();
};

Rychlik::Rychlik(string oznaceni, bool jeZapojen, char* casPrijezdu, char* casOdjezdu) {
	this->oznaceni = oznaceni;
	this->jeZapojen = jeZapojen;
	this->casPrijezdu = casPrijezdu;
	this->casOdjezdu = casOdjezdu;
}

void Rychlik::toString() {
	cout << "Rychlik c.: " << oznaceni << ", jidelni vuz: " << (jeZapojen?"ZAPOJEN":"NEZAPOJEN") << endl;
	Prijezd();
	Odjezd();
	cout << "\n-------------------------------------------------------------\n";
}

class EuroCity : public Vlak {
protected:
	bool jeZapojenLuzkovyVuz;
public:
	void Prijezd() {cout << "Prijezd EuroCity: " << casPrijezdu << endl;};
	void Odjezd() {cout << "Odjezd EuroCity: " << casOdjezdu;};
	EuroCity(string, bool, char*, char*);
	void toString();
};

EuroCity::EuroCity(string oznaceni, bool jeZapojenLuzkovyVuz, char* casPrijezdu, char* casOdjezdu) {
	this->oznaceni = oznaceni;
	this->jeZapojenLuzkovyVuz = jeZapojenLuzkovyVuz;
	this->casPrijezdu = casPrijezdu;
	this->casOdjezdu = casOdjezdu;
}

void EuroCity::toString() {
	cout << "EuroCity c.: " << oznaceni << ", luzkovy vuz: " << (jeZapojenLuzkovyVuz?"ZAPOJEN":"NEZAPOJEN") << endl;
	Prijezd();
	Odjezd();
	cout << "\n-------------------------------------------------------------\n";
}


class Nakladni : public Vlak {
protected:
	bool jeZapojenLuzkovyVuz;
public:
	void Prijezd() {cout << "Prijezd EuroCity: " << casPrijezdu << endl;};
	void Odjezd() {cout << "Odjezd EuroCity: " << casOdjezdu;};
	enum typNakladu{HUMANITARNI = 1, CHEMICKY = 2, TOPNY = 3, POSTA = 4};
	typNakladu typ;
	Nakladni(string, typNakladu, char*, char*);
	void toString();	
};

Nakladni::Nakladni(string oznaceni, typNakladu typ ,char* casPrijezdu, char* casOdjezdu) {
	this->oznaceni = oznaceni;
	this->casPrijezdu = casPrijezdu;
	this->casOdjezdu = casOdjezdu;
	this->typ = typ;
}

void Nakladni::toString() {
	string typNakladu;
	switch(typ) {
	case 1: typNakladu = "Humanitarni";
		break;
	case 2: typNakladu = "Chemicky";
		break;
	case 3: typNakladu = "Topny";
		break;
	case 4: typNakladu = "Posta";
		break;
	}

	cout << "Nakladni vlak c.: " << oznaceni << ", naklad: " << typNakladu << endl;
	Prijezd();
	Odjezd();
	cout << "\n-------------------------------------------------------------\n";
}
