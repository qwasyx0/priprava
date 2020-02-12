#include "PrvekVyrazu.h"


PrvekVyrazu::PrvekVyrazu()
{
	this->_druhPrvku = EnumDruhPrvku::NEDEFINOVATELNY;
}

PrvekVyrazu::PrvekVyrazu(EnumDruhPrvku druhPrvku)
{
	this->_druhPrvku = druhPrvku;
}

EnumDruhPrvku PrvekVyrazu::dejDruhPrvku()
{
	return _druhPrvku;
}

PrvekVyrazu::~PrvekVyrazu()
{
}
