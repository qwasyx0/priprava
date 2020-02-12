#include <iostream>
#include <fstream>
#include "DataSctrucureException.h"
#include "Seznam.h"
#include "Data.h"
using namespace std;
string* nactiString(int pocet, ifstream& in) {
	string* out;
	out = new string[pocet];
	for (int i = 0; i < pocet; i++) {
		in >> out[i];
	}
	return out;
}
Data* nactiData(string key, ifstream& in) {
	Data* chain = new Data();
	in >> chain->data;
	in >> chain->hash;
	in >> chain->parent;
	chain->key = key;
	return chain;
}

void uloz(Seznam<Data>* seznam) {
	ofstream out{};
	out.open("uloz.txt");

	if (out.is_open()) {
		out << seznam->velikost << endl;
		Prvek<Data>* temp = seznam->dejPrvek(0);
		while (temp != nullptr) {
			out << temp->data->key << endl;
			out << temp->data->data << endl;
			out << temp->data->hash << endl;
			out << temp->data->parent << endl;
			temp = temp->dalsi;
		}	
		out.close();
	}
	
	else {
		cerr << "Soubor se nepodarilo otevrit...";
	}
}

Seznam<Data>* nactiTxt() {
	Seznam<Data>* seznam = new Seznam<Data>();
	ifstream soubor{ "uloz.txt" };
	int pocet;
	soubor >> pocet;	
	for (int i = 0; i < pocet; i++)
	{
		Data* novy = new Data();
		soubor >> novy->key;
		soubor >> novy->data;
		soubor >> novy->hash;
		soubor >> novy->parent;
		seznam->vloz(novy);
	}
	soubor.close();
	//cout << "vypis txt:" << endl;
	//seznam->vypis();
	return seznam;
}
//retezce postupne ukladat sam
void ulozStruktury(Seznam<Data>* seznam) {
	ofstream f{ "uloz.dat", ios_base::out | ios_base::binary };
#define VELIKOST 100 //Pevna velikost nacitani bajtu
	Prvek<Data>* temp = seznam->dejPrvek(0);
	string s{ to_string(seznam->velikost)};
	s.resize(VELIKOST);
	f.write(s.c_str(), s.size());
	while(temp != nullptr){
		s= temp->data->key;
		s.resize(VELIKOST);
		f.write(s.c_str(), s.size());
		s = temp->data->data;
		s.resize(VELIKOST);
		f.write(s.c_str(), s.size());
		s = temp->data->hash;
		s.resize(VELIKOST);
		f.write(s.c_str(), s.size());
		s = temp->data->parent;
		s.resize(VELIKOST);
		f.write(s.c_str(), s.size());
		temp = temp->dalsi;
	}
		
	f.close();
}

Seznam<Data>* nactiBin() {
	ifstream f{ "uloz.dat", ios_base::in | ios_base::binary };
	Seznam<Data>* seznam = new Seznam<Data>();
	char retezec[VELIKOST];
	f.read(retezec, VELIKOST);
	int velikost = stoi(retezec);
	string* data{};
	for (size_t i = 0; i < velikost; i++)
	{
		Data* novy = new Data;
		f.read(retezec, VELIKOST);
		novy->key = retezec;
		f.read(retezec, VELIKOST);
		novy->data = retezec;
		f.read(retezec, VELIKOST);
		novy->hash = retezec;
		f.read(retezec, VELIKOST);
		novy->parent = retezec;
		seznam->vloz(novy);
	}
	f.close();
	delete[] data;
	//cout << "Vypis dat:" << endl;
	//seznam->vypis();
	return seznam;
}
int main(int argc, char* argv[])
{
	try
	{
		Seznam<Data>* seznam = new Seznam<Data>();
		ifstream in{};
		string* data{};
		int pocet = 0;
		in.open("../data/index");
		if (in.is_open()) {
			in >> pocet;
			data = nactiString(pocet, in);
		}
		in.close();
		for (int i = 0; i < pocet; i++) {
			in.open("../data/" + data[i]);
			if (in.is_open()) {
				Data* nacteno = nactiData(data[i], in);
				seznam->vloz(nacteno);
			}
			in.close();
			
		}
		delete[] data;

		seznam->vypis();
		uloz(seznam);
		ulozStruktury(seznam);
		seznam->vymazVse();
		seznam = nactiBin();
		cout << "Vypis dat:" << endl;
		seznam->vypis();
		seznam->vymazVse();
		seznam = nactiTxt();
		cout << "Vypis txt:" << endl;
		seznam->vypis();
		seznam->vymazVse();
		cout << "Vypis nic:" << endl;
		seznam->vypis();
	}
	catch (DataStructureException& ex)
	{
		std::cerr << ex.what();
	}

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	return 0;
}

