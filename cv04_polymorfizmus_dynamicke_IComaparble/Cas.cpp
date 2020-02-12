#include "Cas.h"
#include <algorithm>
using namespace std;

Cas::Cas(int h, int m, int s) /*: _hodiny(m)*/
{
	this->_sekundy = s;
	this->_minuty = m;
	this->_hodiny = h;
}

int Cas::compareTo(IComparable* obj) const
{
	Cas* c = dynamic_cast<Cas*>(obj);
	if (_hodiny == c->_hodiny) {
		if (_minuty == c->_minuty) {
			if (_sekundy == c->_sekundy) {
				return 0;
			}
		}
	}
	if (_hodiny > c->_hodiny) {
		return 1;
	}
	if (_hodiny == c->_hodiny) {
		if (_minuty > c->_minuty) {
			return 1;
		}
		else {
			return -1;
		}
	}
	if (_hodiny == c->_hodiny) {
		if (_minuty == c->_minuty) {
			if (_sekundy > c->_sekundy) {
				return 1;
			}
			else {
				return -1;
			}
		}	
	}
	if (_hodiny < c->_hodiny) {
		return -1;
	}		
}

string Cas::toString() const
{
	return  string ("Hodiny: ")+ to_string(_hodiny) + ", minuty: " + to_string(_minuty) + ", sekundy: " + to_string(_sekundy);
} //kdyz zacinam vypis stringem musim pouzit string("...") jinak to nebude fungovat
