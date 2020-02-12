#pragma once
#include "EnumDruhPrvku.h"

class PrvekVyrazu
{
private:
	EnumDruhPrvku _druhPrvku;
public:
	PrvekVyrazu();
	PrvekVyrazu(EnumDruhPrvku druhPrvku);
	EnumDruhPrvku dejDruhPrvku();
	~PrvekVyrazu();
};

