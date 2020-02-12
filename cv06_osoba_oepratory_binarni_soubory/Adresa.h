#pragma once
#ifndef ADRESA_H
#define ADRESA_H
#include <string>
struct Adresa {
public:
	Adresa();
	Adresa(std::string ulice, std::string mesto, int psc);
	std::string getUlice() const;
	std::string getMesto() const;
	int getPsc() const;
	void setUlice(std::string ulice);
	void setMesto(std::string mesto);
	void setPsc(int psc);
	std::string toString() const;
private:
	std::string _ulice;
	std::string _mesto;
	int _psc;
};
std::ostream& operator<<(std::ostream& os, const Adresa& adresa);
std::istream& operator>>(std::istream& is, Adresa& adresa);
#endif // ADRESA_H