#pragma once
#ifndef ZPRAVAPORT_H
#define ZPRAVAPORT_H
#include <string>
#include <iostream>
#include "zprava.h"
struct ZpravaPort {
	Zprava* zprava;
	ASitovyPrvek* port;
	ZpravaPort() { }
	ZpravaPort(Zprava* zprava, ASitovyPrvek* port) : zprava(zprava), port(port) {
	}
};
#endif //!ZPRAVAPORT_H
