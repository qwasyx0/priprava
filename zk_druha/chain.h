#ifndef _CHAIN_H
#define _CHAIN_H
#include <string>
class Chain {
public:
	Chain();
	Chain(std::string _key, std::string _data, std::string _hash, std::string _parent);
	~Chain();
	std::string key;
	std::string data;
	std::string hash;
	std::string parent;
};

#endif // !CHAIN_H
