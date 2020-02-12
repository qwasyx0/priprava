#ifndef _PRVEK_H
#define _PRVEK_H

template <class T>
class Prvek {
public:
	Prvek();
	~Prvek();
	T* data;
	Prvek<T>* dalsi;
	Prvek<T>* predchozi;
};

#endif // !PRVEK_H

template<class T>
inline Prvek<T>::Prvek()
{
	dalsi = nullptr;
	predchozi = nullptr;
}

template<class T>
inline Prvek<T>::~Prvek()
{
	delete data;
}
