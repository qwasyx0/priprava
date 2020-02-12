#ifndef __DBAPI_H
#define __DBAPI_H
#include "exceptions.h"
#include "platform.h"
#include <functional>

// Typ datového pole
enum struct FieldType {
	Integer,
	Double,
	String,
	Field
};

// Polymorfní datový objekt (reprezentuje jednu datovou hodnotu v tabulce)
// Rozhraní vyhovuje základním typům int, double, string; pro typ „field“ je rozhraní rozšířeno
class DLL_SPEC Object {
public:
	Object(){}
	virtual ~Object(){}

	// Gettery a settery podle typu
	// Jejich funkce je definována jen v případě, že aktuální objekt je odpovídajícího typu
	// Automatické konverze v základním API nejsou vyžadovány

	virtual std::string getString() const {throw std::exception("Impementation not needed.");};
	virtual void setString(std::string value){throw std::exception("Impementation not needed.");};

	virtual int getInt() const {throw std::exception("Impementation not needed.");};
	virtual void setInt(int value)  {throw std::exception("Impementation not needed.");};

	virtual double getDouble() const {throw std::exception("Impementation not needed.");};
	virtual void setDouble(double value){throw std::exception("Impementation not needed.");};

	// Vrací true, pokud aktuální objekt představuje daný typ
	virtual bool isType(FieldType type) const {throw std::exception("Impementation not needed.");};
};


class DLL_SPEC IntObject : public Object {
public:
	IntObject() : value(0) {}
	IntObject(int v) : value(v) {}
	bool isType(FieldType type) const;
	int getInt() const { return value; }

private:
	int value;
};

class DLL_SPEC DoubleObject : public Object {
public:
	DoubleObject() : value(0.0) {}
	DoubleObject(double v) : value(v) {}
	bool isType(FieldType type) const;
	double getDouble() const { return value; }
private:
	double value;
};

class DLL_SPEC StringObject : public Object {
public:
	StringObject() : value("") {}
	StringObject(std::string v) : value(v) {}
	bool isType(FieldType type) const;
	std::string getString() const { return value; }
private:
	std::string value;
};

// Objekt popisující sloupeček „field“
class DLL_SPEC FieldObject : public Object {
public:
	FieldObject() {}
	FieldObject(std::string name, FieldType type) :name(name), type(type) {}

	virtual bool isType(FieldType type) const override;

	// Název sloupečku
	std::string getName() const { return name; }
	// Typ sloupečku
	FieldType getType() const { return type; }
	int getColumns() const { return columns; }
	int getRows() const { return rows; }
	std::string getTableName() const { return tableName; }
	std::string getDatabaseName() const { return databaseName; }
	void setName(std::string name);
	void setType(FieldType type);
	void setColumns(int columns);
	void setRows(int rows);
	void setTableName(std::string tableName);
	void setDatabaseName(std::string databaseName);
private:
	int columns;
	int rows;
	std::string databaseName;
	std::string tableName;
	std::string name;
	FieldType type;
};

// Rozhraní iterátoru (select)
class DLL_SPEC Iterator {
public:
	virtual ~Iterator() {}
	// Posun na další řádek (vrací true, pokud je iterátor platný; logika podle Java Iterator)
	virtual bool moveNext() = 0;
	// Vrací pole Object* obsahující data řádku
	virtual Object** getRow() = 0;
	// Vrací interní rowId aktuálního řádku
	virtual int getRowId() = 0;
	// Uzavøe iterátor (dealokuje paměťové prostředky)
	virtual void close() = 0;
};
// --------------------------------------------------------
// Rozhraní definující podmínku – pouze pro bonusové metody
class DLL_SPEC Condition {
	virtual ~Condition() { }
	virtual bool matches(int fieldCount, FieldObject** fields, Object** row) const = 0;
};
// --------------------------------------------------------
// Tabulka
class DLL_SPEC Table {
	class TableIterator : public Iterator {
	public:
		TableIterator() {}
		virtual ~TableIterator() {}
		TableIterator(Table* table);
		virtual bool Iterator::moveNext() override;
		virtual Object** Iterator::getRow() override;
		virtual int Iterator::getRowId() override;
		virtual void Iterator::close() override;
	private:
		Table* table = nullptr;
		int currentRowCounter = 0;
		Object** currentRow = nullptr;
		int columnsIter = 0;
		int rowsIter = 0;
	};
public:
	Table(std::string databaseName, std::string tableName, int fieldsCount, int rowsCount, int foreignKeysCount, FieldObject** fields, Object*** foreignKeys);
	// Vložení nového řádku do tabulky (pole Object* (pro jednotlivé hodnoty sloupeèkù))
	void insert(Object** row);
	// Smazání vybraného řádku z tabulky
	void remove(int rowid);
	// Select – vytvoří iterátor k procházení tabulky
	Iterator* select();
	// Commit – přenese změny z paměti do datových souborů
	void commit();
	// Uzavře tabulku (dealokuje paměťové prostředky)
	void close();
	// Vrací počet řádkù v tabulce
	int getRowCount() const;
	// Vrací pole FieldObject* popisující sloupečky tabulky
	FieldObject** getFields() const;
	// Vrací počet sloupečkù
	int getFieldCount() const;
	// Vrací název tabulky
	std::string getTableName();
	//Nastaví foreign key na columnIndex jine tabulky
	void setForeignKey(int columnAlterIndex, int columnReferenceIndex, Table* reference);
	//Funkce vrátí počet cizich klicu v tabulce
	int getForeignKeysCount() const;
	//Funkce vrátí strukturu cizích klíčů
	Object*** getForeignKeys() const;
	//Vypsani struktury cizich klicu
	void printForeignKeys() const;
	//Vypsani metadat tabulky
	void printStructure() const;
	// ============== Bonusové metody: ================
		// Select s podmínkou
	Iterator* select(Condition* condition) { throw 0; }
	// Nalezení rowId s podmínkou
	int findRowId(Condition* condition) { throw 0; }
	// Update – aktualizuje øádky vyhovující podmínce, aktualizaci provádí funkce „callback“
	// callback na vstupu obdrží data øádku a vrací data
	void update(Condition* condition, std::function<void(Object**)> callback) { throw 0; }
private:
	int rows;
	int columns;
	Object*** data;
	FieldObject** structure;
	std::string tableName;
	std::string databaseName;
	TableIterator* tableIterator;
	Object*** foreignKeys;
	int foreignKeysCount;
};

// Databáze
class DLL_SPEC Db {
public:
	// Otevře databázi
	static Db* open(std::string database);
	// Uzavře databázi (dealokuje paměové prostředky)
	void close();

	// Vytvoří novou tabulku
	Table* createTable(std::string name, int fieldsCount, FieldObject** fields);
	// Otevře existující tabulku
	Table* openTable(std::string name);
	// Otevře tabulku (pokud neexistuje, vytvoří automaticky novou)
	Table* openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields);

	// Alokuje objekt „int“
	static Object* Int(int value);
	// Alokuje objekt „double“
	static Object* Double(double value);
	// Alokuje objekt „string“
	static Object* String(std::string value);
	// Alokuje objekt „field“
	static FieldObject* Field(std::string name, FieldType type);

	//Nastaví cizí klíč na jinou tabulku v databázi
	bool setForeignKey(int columnAlterIndex, Table* alter, int columnReferenceIndex, Table* reference);
	//Vytvoří strukturu pro ukládání názvů tabulek databáze
	Object** createTables();
	//Přidá tabulku do seznamu tabulek databáze
	Object** addNewTable(StringObject newTable);
	//Metoda vrati pocet tabulek v databazi
	int getTableCount() { return tableCount; }
	//Vypis nazvu tabulek databaze
	void printTables();
private:
	std::string databaseName;
	Object** tables;
	int tableCount;

};
#endif //__DBAPI_H