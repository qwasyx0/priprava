#include <iostream>
#include "Osoba.h"
#include "TelefonniSeznam.h"
#include "PrvekSeznamu.h"

using namespace Entity;
using namespace Model;
int main()
{

	//Entity::Osoba::PrvekSeznamu* prvekSeznamu = new Entity::Osoba::PrvekSeznamu(*new Osoba{ "Tomas", "123654789", 1 });
	TelefonniSeznam** seznam = new TelefonniSeznam * [10];
	
	seznam[0]->pridejOsobu({ "Tomas", "123654789", 1 });
	seznam[1]->pridejOsobu({ "Jakub", "145874589", 2 });
	seznam[2]->pridejOsobu({ "Honza", "145875896", 3 });
	seznam[3]->pridejOsobu({ "Martin", "125478954", 4 });
	seznam[4]->pridejOsobu({ "Jarek", "885848458", 5 });
	seznam[5]->pridejOsobu({ "Pavla", "874165165", 6 });
	seznam[6]->pridejOsobu({ "Amalie", "811111444", 7 });
	seznam[7]->pridejOsobu({ "Jiri", "7847847444", 8 });
	seznam[8]->pridejOsobu({ "Pavel", "7849161111", 9 });
	seznam[9]->pridejOsobu({ "Ondra", "7474111145", 10 });


}












