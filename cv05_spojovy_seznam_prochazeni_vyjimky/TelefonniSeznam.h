#pragma once
#ifndef __TelefonniSeznam_h
#define __TelefonniSeznam_h
#include "Osoba.h"

namespace Model {
	struct TelefonniSeznam {
	private:
		Entity::Osoba::PrvekSeznamu* _zacatek;
	public:
		TelefonniSeznam();
		~TelefonniSeznam();
		void pridejOsobu(Entity::Osoba o);
		std::string najdiTelefon(std::string jmeno) const;
		std::string najdiTelefon(int id) const;
	};
}
#endif // __TelefonniSeznam_h

