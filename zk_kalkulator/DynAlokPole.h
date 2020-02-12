#pragma once

template<typename T>
class DynAlokPole
{
private:
	T* _polePrvku;
	int _pocetPrvku;
public:
	DynAlokPole();
	void pridejPrvek(T prvek);
	T dejPrvekNaPozici(const int& pozice);
	int dejPocetPrvku();
	~DynAlokPole();
};


template<typename T>
DynAlokPole<T>::DynAlokPole()
{
	this->_pocetPrvku = 0;
	this->_polePrvku = new T[_pocetPrvku];
}

template<typename T>
void DynAlokPole<T>::pridejPrvek(T prvek)
{
	//navýšení poètu prvkù
	_pocetPrvku++;
	//realokace pole
	T* polePrvkuNove = new T[_pocetPrvku];
	memcpy(polePrvkuNove, _polePrvku, (_pocetPrvku - 1) * sizeof(_polePrvku));
	delete[] _polePrvku;
	_polePrvku = polePrvkuNove;

	//pøidání prvku
	_polePrvku[_pocetPrvku - 1] = prvek;

}

template<typename T>
T DynAlokPole<T>::dejPrvekNaPozici(const int & pozice)
{
	if (pozice<0 || pozice>_pocetPrvku - 1)
	{
		throw 100;
	}
	else {
		return _polePrvku[pozice];
	}
}

template<typename T>
int DynAlokPole<T>::dejPocetPrvku()
{
	return _pocetPrvku;
}

template<typename T>
DynAlokPole<T>::~DynAlokPole()
{
	delete[] _polePrvku;
}
