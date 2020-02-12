#ifndef SEZNAM_H
#define SEZNAM_H
#include "prvek.h"

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
	T* dejPrvek(int index);
	T* dejPosledni();
	void vymazVse();
};
#endif

template<class T>
inline Seznam<T>::Seznam()
{
	prvni = nullptr;
	velikost = 0;
}

template<class T>
inline Seznam<T>::~Seznam()
{
	delete prvni;
	delete aktualni;
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
	}else if (velikost > 0) {
		Prvek<T>* pom = prvni;
		while (pom->dalsi != nullptr) {
			pom = pom->dalsi;
		}
		Prvek<T>* novy = new Prvek<T>();
		novy->data = data;
		novy->predchozi = pom;
		pom->dalsi = novy;
		velikost ++ ;
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

template<class T>
inline T* Seznam<T>::dejPrvek(int index)
{
	Prvek<T>* pom = prvni;
	for (int i = 0; i <= index;i++) {
		pom = pom->dalsi;
	}
	return pom->data;
}

template<class T>
inline T * Seznam<T>::dejPosledni()
{
	Prvek<T>* pom = prvni;
	while (pom->dalsi != nullptr) {
		pom = pom->dalsi;
	}
	return pom->data;
}

template<class T>
inline void Seznam<T>::vymazVse()
{
	prvni = nullptr;
	aktualni = nullptr;
	velikost = 0;
}
