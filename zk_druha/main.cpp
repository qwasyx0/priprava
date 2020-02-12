#include "seznam.h"
#include "chain.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*bool overHasheSeznamu(Seznam<Chain> seznam)
{
	for (int i = 0; i < seznam.velikost; i++) {
		Chain*potomek = seznam.dejPrvek(i);
		Chain*predek = seznam.dejPrvek(i + 1);
		if (!overHash(predek, potomek)) {
			return false;
		}
	}
	return true;
}

bool overHash(Chain* predek, Chain* potomek) {
	int hash = 0x66;
	const char * ch = new char[potomek->data.length + 1];
	ch = potomek->data.c_str();
	for (int i = 0; i < potomek->data.length; i++) {
		hash += (int)ch[i];
	}
	ch = new char[potomek->key.length + 1];
	ch = potomek->data.c_str();
	for (int i = 0; i < potomek->key.length; i++) {
		hash += (int)ch[i];
	}
	ch = new char[predek->key.length + 1];
	ch = potomek->data.c_str();
	for (int i = 0; i < predek->key.length; i++) {
		hash += (int)ch[i];
	}
	ch = new char[predek->hash.length + 1];
	ch = potomek->data.c_str();
	for (int i = 0; i < predek->hash.length; i++) {
		hash += (int)ch[i];
	}
	if (hash == stoi(potomek->hash)) {
		return true;
	}
	else {
		return false;
	}
}*/

string* nactiKlice(int pocet, ifstream& in) {
	string*klice;
	klice = new string[pocet];
	for (int i = 0; i < pocet;i++) {
		in >> klice[i];
	}
	return klice;
}

Chain* nactiChain(ifstream& in,string key) {
	Chain* chain = new Chain();
	in >> chain->data;
	in >> chain->hash;
	in >> chain->parent;
	chain->key = key;
	return chain;
}

Chain* najdiDalsi(string parent,int pocetKlicu, string*klice) {
	ifstream inChains{ };
	for (int i = 0; i < pocetKlicu; i++) {
		inChains.open("data/" + klice[i]);
		Chain* nacteny = nactiChain(inChains, klice[i]);
		inChains.close();
		if (nacteny->key == parent) {
			return nacteny;
		}
	}
	return nullptr;
}

int main() {
	//nacteni klicu
	int pocetKlicu = 0;
	string *klice;
	ifstream in{};
	in.open("data/index");
	
		in >> pocetKlicu;
		klice = nactiKlice(pocetKlicu,in);
		in.close();
	

	//vytvoreni seznamu chainu
	Chain* nejdelsi;
	int nejdelsiCesta = 0;
	Seznam<Chain> seznam = Seznam<Chain>();
	ifstream inChains{};

	for (int i = 0; i < pocetKlicu; i++) {
		inChains.open("data/" + klice[i]);
		Chain* prvek = nactiChain(inChains,klice[i]);
		seznam.vloz(prvek);
		Chain* aktualniPrvek = najdiDalsi(seznam.aktualni->data->parent, pocetKlicu, klice);
		while (aktualniPrvek != nullptr) {
			seznam.vloz(aktualniPrvek);
			aktualniPrvek = najdiDalsi(seznam.aktualni->data->parent, pocetKlicu, klice);
		}
		bool overeniHash = false;
		if (seznam.velikost > nejdelsiCesta&&overeniHash&&seznam.dejPosledni()->key=="000000") {
			nejdelsi = seznam.dejPrvek(0);
		}
		seznam.vymazVse();
	}

	cout << "Nejdelsi chain: " << endl;

	cin.get();
	return 0;
}

