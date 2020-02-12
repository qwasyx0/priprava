#pragma once
#ifndef __Osoba_h
#define __Osoba_h
#include <string>

namespace Entity {
	struct Osoba {
		struct PrvekSeznamu {
			PrvekSeznamu* dalsi;
			Entity::Osoba data;
			PrvekSeznamu(Entity::Osoba data);
			PrvekSeznamu();
		};

	private:
		std::string jmeno;
		std::string telefon;
		int id;
	public:
		Osoba(std::string jmeno, std::string telefon, int id);
		~Osoba();
		void setJmeno(std::string jm);
		void setTelefon(std::string tel);
		void setId(int id);
		std::string getJmeno() const;
		std::string getTelefon() const;
		int getId() const;
	};
}
#endif // __Osoba_h