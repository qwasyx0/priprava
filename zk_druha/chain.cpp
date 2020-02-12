#include "chain.h"

Chain::Chain() {

}
Chain::Chain(std::string _key, std::string _data, std::string _hash, std::string _parent) {
	key = _key;
	data = _data;
	hash = _hash;
	parent = _parent;
}

Chain::~Chain()
{
}


