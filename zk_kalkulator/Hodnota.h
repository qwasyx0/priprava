#pragma once
#include "PrvekVyrazu.h"

template <typename T>
class Hodnota : public PrvekVyrazu
{
private:
	T _hodnota;
public:
	Hodnota();
	Hodnota(T hodnota);
	T dejHodnotu() const;
	~Hodnota();
};

template<typename T>
Hodnota<T>::Hodnota() : PrvekVyrazu(EnumDruhPrvku::HODNOTA) 
{

}

template<typename T>
Hodnota<T>::Hodnota(T hodnota) : PrvekVyrazu(EnumDruhPrvku::HODNOTA)
{
	this->_hodnota = hodnota;
}



template<typename T>
T Hodnota<T>::dejHodnotu() const {
	return this->_hodnota;
}

template<typename T>
Hodnota<T>::~Hodnota()
{
}
