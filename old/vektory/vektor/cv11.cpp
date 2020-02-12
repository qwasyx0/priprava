// cv11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Vector3D.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Vector3D *a = new Vector3D();
	Vector3D *b = new Vector3D();
	a->readValues();
	b->readValues();
	cout >> a*b;
	system("pased");
	return 0;
}

