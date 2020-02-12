#pragma once
#ifndef _UCETENKA_H
#define _UCETENKA_H
struct Uctenka
{
private:
	int cisloUctenky;
	double castka;
	double dph;
public:
	void setCisloUctenky(int cisloUctenky);
	int getCisloUctenky(); //preferuje se nekonstantni metoda kdyz je jich vice
	int getCisloUctenky() const;
	void setCastka(double castka);
	double getCastka() const;
	void setDph(double dph);
	double getDph() const;
};
#endif