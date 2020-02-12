#pragma warning(disable:4715)
#include "helpful.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>
#include <string>
using namespace std;
Table* Db::openTable(std::string name) {
	ifstream tableStruct{ this->databaseName + '_' + name + "_struct.txt" };
	int fieldCount;
	int rowCount;
	int foreignKeysCount;
	std::string databaseNameOpen;
	std::string tableNameOpen;
	tableStruct >> rowCount;
	tableStruct >> fieldCount;
	tableStruct >> foreignKeysCount;
	tableStruct >> databaseNameOpen;
	tableStruct >> tableNameOpen;
	vector<std::string> columnNames;
	vector<FieldType> columnTypes;
	string b;
	for (int i = 0; i < fieldCount; i++) {
		tableStruct >> b;
		columnNames.push_back(b);
	}
	for (int i = 0; i < fieldCount; i++) {
		tableStruct >> b;
		FieldType typ;
		if (b == "String") {
			typ = FieldType::String;
		}
		else if (b == "Integer") {
			typ = FieldType::Integer;
		}
		else if (b == "Double"){
			typ = FieldType::Double;
		}
		else {
			cout << "OpenTableChyba pri pretypovani string na FieldType - neznamy typ" << endl;
		}
		columnTypes.push_back(typ);
	}
	Object*** foreignKeys = nullptr;
	if (foreignKeysCount > 0) {
		foreignKeys = new Object**[foreignKeysCount];
		for (int i = 0; i < foreignKeysCount; i++) {

			foreignKeys[i] = new Object * [4];
			int a;
			tableStruct >> a;
			IntObject* newI = new IntObject(a);
			foreignKeys[i][0] = newI;
			tableStruct >> b;
			StringObject* newS = new StringObject(b);
			foreignKeys[i][1] = newS;
			tableStruct >> a;
			IntObject* newI1 = new IntObject(a);
			foreignKeys[i][2] = newI1;
			tableStruct >> b;
			StringObject* newS1 = new StringObject(b);
			foreignKeys[i][3] = newS1;
		}
	}
	tableStruct.close();
	FieldObject* prvni;
	FieldObject* druhy;
	FieldObject* treti;
	FieldObject* ctvrty;
	FieldObject* paty;
	FieldObject** fields = nullptr;
	switch (fieldCount) {
	case 1:
		prvni = Db::Field(columnNames[0], columnTypes[0]);
		fields = combineToDefinition(prvni);
		break;
	case 2:
		prvni = Db::Field(columnNames.at(0), columnTypes.at(0));
		druhy = Db::Field(columnNames.at(1), columnTypes.at(1));
		fields = combineToDefinition(prvni,druhy);
		break;
	case 3:
		prvni = Db::Field(columnNames.at(0), columnTypes.at(0));
		druhy = Db::Field(columnNames.at(1), columnTypes.at(1));
		treti = Db::Field(columnNames.at(2), columnTypes.at(2));
		fields = combineToDefinition(prvni, druhy, treti);
		break;
	case 4:
		prvni = Db::Field(columnNames.at(0), columnTypes.at(0));
		druhy = Db::Field(columnNames.at(1), columnTypes.at(1));
		treti = Db::Field(columnNames.at(2), columnTypes.at(2));
		ctvrty = Db::Field(columnNames.at(3), columnTypes.at(3));
		fields = combineToDefinition(prvni, druhy, treti, ctvrty);
		break;
	case 5:
		prvni = Db::Field(columnNames.at(0), columnTypes.at(0));
		druhy = Db::Field(columnNames.at(1), columnTypes.at(1));
		treti = Db::Field(columnNames.at(2), columnTypes.at(2));
		ctvrty = Db::Field(columnNames.at(3), columnTypes.at(3));
		paty = Db::Field(columnNames.at(4), columnTypes.at(4));
		fields = combineToDefinition(prvni, druhy, treti, ctvrty, paty);
		break;
	default:
		cout << "OpenTableChyba pri sestavovani fields" << endl;
		break;
	}
	Table* returnTable = returnTable = new Table(this->databaseName, name, fieldCount, 0, foreignKeysCount, fields, foreignKeys);
	this->tables = addNewTable(name);
	ifstream tableData{ this->databaseName + '_' + name + "_data.txt" };
	for (int j = 0; j < rowCount; j++) {
		string rowString;
		double rowDouble;
		int rowInt;
		Object* returning1 = nullptr;
		Object* returning2 = nullptr;
		Object* returning3 = nullptr;
		Object* returning4 = nullptr;
		Object* returning5 = nullptr;
		Object** row = nullptr;
		for (int i = 0; i < fieldCount; i++) {
			switch (fields[i]->getType()) {
			case FieldType::Integer:
				getline(tableData, rowString, ';');
				rowInt = stoi(rowString);
				switch (i) {
				case 0:
					returning1 = Db::Int(rowInt);
					break;
				case 1:
					returning2 = Db::Int(rowInt);
					break;
				case 2:
					returning3 = Db::Int(rowInt);
					break;
				case 3:
					returning4 = Db::Int(rowInt);
					break;
				case 4:
					returning5 = Db::Int(rowInt);
					break;
				default:
					cout << "OpenTable - number of rows is greater than 6" << endl;
					break;
				}
				break;
			case FieldType::Double:
				getline(tableData, rowString, ';');
				rowDouble = stod(rowString);
				switch (i) {
				case 0:
					returning1 = Db::Double(rowDouble);
					break;
				case 1:
					returning2 = Db::Double(rowDouble);
					break;
				case 2:
					returning3 = Db::Double(rowDouble);
					break;
				case 3:
					returning4 = Db::Double(rowDouble);
					break;
				case 4:
					returning5 = Db::Double(rowDouble);
					break;
				default:
					cout << "OpenTable - number of rows is greater than 6" << endl;
					break;
				}
				break;
			case FieldType::String:
				getline(tableData, rowString, ';');
				switch (i) {
				case 0:
					returning1 = Db::String(rowString);
					break;
				case 1:
					returning2 = Db::String(rowString);
					break;
				case 2:
					returning3 = Db::String(rowString);
					break;
				case 3:
					returning4 = Db::String(rowString);
					break;
				case 4:
					returning5 = Db::String(rowString);
					break;
				default:
					cout << "OpenTable - number of rows is greater than 6" << endl;
					break;
				}
				break;
			default:
				cout << "OpenTable - Chyba neznamy typ pri importu dat" <<endl;
				break;
			}
			
		}
		switch (fieldCount) {
		case 1:
			row = combineToRow(returning1);
			break;
		case 2:
			row = combineToRow(returning1, returning2);
			break;
		case 3:
			row = combineToRow(returning1, returning2, returning3);
			break;
		case 4:
			row = combineToRow(returning1, returning2, returning3, returning4);
			break;
		case 5:
			row = combineToRow(returning1, returning2, returning3, returning4, returning5);
			break;
		default:
			cout << "OpenTable - Chyba pri kombinovani do row pri importu dat"<< endl;
			break;
		}
		returnTable->insert(row);
	}
	tableData.close();
	return returnTable;
}

Db* Db::open(std::string database)
{
	Db* db = new Db();
	db->databaseName = database;
	db->tableCount = 0;
	return db;
}

void Db::close() {
	if (tableCount > 0) {
		for (int i = 0; i < tableCount; i++) {
			delete tables[i];
		}
		delete[] tables;
	}
	delete this;
}

Table* Db::createTable(std::string name, int fieldsCount, FieldObject** fields)
{
	Table* t = new Table(this->databaseName, name, fieldsCount,0,0, fields, nullptr);
	this->tables = addNewTable(name);
	return t;

}


Table* Db::openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields)
{
	Table* t = nullptr;
	if (filesystem::exists("../DemonstracniAplikace/" + this->databaseName + '_' + name + "_struct.txt")) {
		
		t = openTable(name);
		for (int i = 0; i < fieldsCount; i++) {
			delete fields[i];
		}
		delete[] fields;
	}
	else {
		t = createTable(name, fieldsCount, fields);
	}
	return t;
}

Object* Db::Int(int value)
{
	IntObject* newInt = new IntObject(value);
	return newInt;
}

Object* Db::Double(double value)
{
	DoubleObject* newDouble = new DoubleObject(value);
	return newDouble;
}

Object* Db::String(std::string value)
{
	StringObject* newString = new StringObject(value);
	return newString;
}

FieldObject* Db::Field(std::string name, FieldType type)
{
	FieldObject* vratit = new FieldObject(name, type);
	return vratit;
}

bool Db::setForeignKey(int columnAlterIndex, Table* alter, int columnReferenceIndex, Table* reference)
{
	if (alter != nullptr && reference != nullptr) {

		FieldObject** alterStructure = nullptr;
		for (int i = 0; i < alter->getFieldCount(); i++) {
			alterStructure = alter[i].getFields();
		}
		FieldObject** referenceStructure = nullptr;
		for (int i = 0; i < reference->getFieldCount(); i++) {
			referenceStructure = reference[i].getFields();
		}
		bool jeOk1 = false;
		bool jeOk2 = false;
		if (alter != NULL) {
			jeOk1 = alterStructure[columnAlterIndex]->isType(FieldType::Integer);
		}
		else {
			cout << "SetForeignKey - tabulka alter je prazdna"<< endl;
		}
		if (reference != NULL) {
			jeOk2 = referenceStructure[columnReferenceIndex]->isType(FieldType::Integer);
		}
		else {
			cout << "SetForeignKey - tabulka reference je prazdna" << endl;
		}
		if (jeOk1 && jeOk2) {
			if (alter->getForeignKeysCount() < 6 && alter->getForeignKeysCount() >= 0) {
				alter->setForeignKey(columnAlterIndex, columnReferenceIndex, reference);
			}

		}
		else {
			cout << "SetForeignKey - Nelze propojit tabulky cizim klicem, zadane sloupce nejsou integer a neshoduji se"<< endl;
			return false;
		}
	}
	else {
		cout << "SetForeignKey - Nelze propojit tabulky cizim klicem, zadane sloupce nejsou integer a neshoduji se"<< endl;
		return false;
	}
	return true;
}

Object** Db::createTables() {
	Object** tables = new Object * [1];
	return tables;
}

Object** Db::addNewTable(StringObject newTable) {
	Object** returnTables = nullptr;
	if (this->tableCount == 0) {
		returnTables = createTables();
	} else {

		Object** temp = new Object * [tableCount+1];
		for (int i = 0; i < tableCount; i++) {
			temp[i] = this->tables[i];
		}

		delete[] this->tables;
		returnTables = temp;

	}
	
	StringObject* ret = new StringObject(newTable);
	returnTables[tableCount] = ret;
	this->tableCount = tableCount + 1;

	return returnTables;
}

void Db::printTables()
{
	for (int i = 0; i < tableCount; i++) {
		cout << "Nazev tabulky:\t" << this->tables[i][0].getString() << endl;
	}
	cout << endl;
}
