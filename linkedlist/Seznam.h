#ifndef SEZNAM_H
#define SEZNAM_H
#include "Prvek.h"
#include <string>
#include <sstream>

template <class T>
class Seznam {
private:
	Prvek<T>* prvni;
public:
	Prvek<T>* aktualni;
	int velikost;
	Seznam();
	~Seznam();
	void vloz(T* data);
	void odeber(int index);
	void odeberPrvni();
	void odeberPosledni();
	Prvek<T>* dejPrvek(int index);
	Prvek<T>* dejPosledni();
	void vypis();
	void vymazVse();
};
#endif

template<class T>
inline Seznam<T>::Seznam()
{
	prvni = nullptr;
	aktualni = nullptr;
	velikost = 0;
}

template<class T>
inline Seznam<T>::~Seznam()
{
}

template<class T>
inline void Seznam<T>::vloz(T* data)
{
	if (velikost == 0) {
		prvni = new Prvek<T>();
		prvni->data = data;
		prvni->dalsi = nullptr;
		prvni->predchozi = nullptr;
		velikost++;
		aktualni = prvni;
	}
	else if (velikost > 0) {
		Prvek<T>* pom = prvni;
		while (pom->dalsi != nullptr) {
			pom = pom->dalsi;
		}
		Prvek<T>* novy = new Prvek<T>();
		novy->data = data;
		novy->predchozi = pom;
		pom->dalsi = novy;
		velikost++;
		aktualni = novy;
	}
}


template<class T>
inline void Seznam<T>::odeber(int index)
{
	Prvek<T>* pom = prvni;
	for (int i = 0; i < velikost; i++) {
		if (i == index) {
			pom.dalsi.predchozi = pom.predchozi;
			pom.predchozi.dalsi = pom.dalsi;
			velikost--;
		}
		else {
			pom = pom.dalsi;
		}
	}
}

template <class T>
inline void Seznam<T>::odeberPrvni() {
	if (prvni != nullptr) {
		Prvek<T>* temp = prvni;
		prvni = prvni->dalsi;
		delete temp;
	}
	else {
		throw DataStructureException("odeberPrvni: prvni is nullptr");
	}
}
template<class T>
inline void Seznam<T>::odeberPosledni()
{
	if (prvni != nullptr)
	{
		Prvek<T>* temp = prvni;
		prvni = prvni->predchozi;
		delete temp;
		velikost--;
	}
	else
	{
		throw DataStructureException("odeberPosledni: posledni is nullptr");
	}
}
template<class T>
inline Prvek<T>* Seznam<T>::dejPrvek(int index)
{
	Prvek<T>* pom = prvni;
	if (index <= this->velikost) {

	for (int i = 0; i < index; i++) {
		pom = pom->dalsi;
	}
	return pom;
	}
	else {
		throw DataStructureException("dejPrvek: index out of bounds");
	}
}


template<class T>
inline Prvek<T>* Seznam<T>::dejPosledni()
{
	Prvek<T>* pom = prvni;
	while (pom->dalsi != nullptr) {
		pom = pom->dalsi;
	}
	return pom;
}

template<class T>
inline void Seznam<T>::vymazVse()
{
	aktualni = nullptr;
	if (prvni != nullptr) {
		for (int i = 0; i < velikost; i++)
		{
			Prvek<T>* del = prvni;
			prvni = prvni->dalsi;
			delete del;
		}
		velikost = 0;
	}
	delete this;
}

template<typename T>
inline void Seznam<T>::vypis()
{
	if (velikost > 0)
	{
		Prvek<T>* temp = prvni;
		for (int i = 0; i < velikost; i++)
		{
			std::cout << "'key':'" << temp->data->key << "','data':" << temp->data->data << "','hash':" << temp->data->hash << "','parent':" << temp->data->parent << std::endl;
			temp = temp->dalsi;
		}
	}
}

