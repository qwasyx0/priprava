#include "dbapi.h"

Object::Object()
{
}

Object::~Object()
{
}

std::string Object::getString() const
{
	return std::string();
}

void Object::setString(std::string value)
{
}

int Object::getInt() const
{
	return 0;
}

void Object::setInt(int value)
{
}

double Object::getDouble() const
{
	return 0.0;
}

void Object::setDouble(double value)
{
}

bool Object::isType(FieldType type) const
{
	return false;
}

bool FieldObject::isType(FieldType type) const
{
	return false;
}

Iterator::~Iterator()
{
}

Iterator* Table::select()
{
	return nullptr;
}

int Table::getRowCount() const
{
	return 0;
}

FieldObject** Table::getFields() const
{
	return nullptr;
}

int Table::getFieldCount() const
{
	return 0;
}

Db* Db::open(std::string database)
{
	return nullptr;
}

void Db::close()
{
}

Table* Db::createTable(std::string name, int fieldsCount, FieldObject** fields)
{
	return nullptr;
}

Table* Db::openTable(std::string name)
{
	return nullptr;
}

Table* Db::openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields)
{
	return nullptr;
}

Object* Db::Int(int value)
{
	return nullptr;
}

Object* Db::Double(double value)
{
	return nullptr;
}

Object* Db::String(std::string value)
{
	return nullptr;
}

FieldObject* Db::Field(std::string name, FieldType type)
{
	return nullptr;
}

void Table::HelloWorld()
{
	std::cout << "Hello World from DLL library" << std::endl;
}
