#pragma once
#include "stdafx.h"
#include <string>
#include "SpojovySeznam.h"

using namespace std;

struct Prvek {
public:
	string klic;
	Prvek* dalsi;
	SpojovySeznam data;

public:
	Prvek();
	Prvek(string klic);
};