#pragma once
#ifndef __Cas_h
#define __Cas_h
#include "IComparable.h"
#include "IObject.h"
#include <string>

struct Cas : IComparable {
public:
	Cas(int h, int m, int s);
	virtual int compareTo(IComparable* obj) const override;
	virtual string toString() const override;
private:
	int _sekundy;
	int _minuty;
	int _hodiny;
};
#endif // Cas_h