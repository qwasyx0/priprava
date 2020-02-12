#ifndef _DATA_H
#define _DATA_H
#include <string>
class Data {
public:
	Data() {};
	Data(std::string _key, std::string _data, std::string _hash, std::string _parent) : key(_key), data(_data), hash(_hash), parent(_parent) {};
	~Data() {};
	std::string key;
	std::string data;
	std::string hash;
	std::string parent;
};

#endif // !CHAIN_H
