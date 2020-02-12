#include "StdAfx.h"
#include "Vector3D.h"


Vector3D::Vector3D() { }
Vector3D::~Vector3D() { }

void Vector3D::set(double _ax, double _ay, double _az) {
	x = _ax;
	y = _ay;
	z = _az;
}

void Vector3D::readValues(){
	double pom;
	cout << "zadej 3 souradnice vektoru: \nX: ";

	cin >> pom;
	x = pom;
	cout << "\nY:";
	cin >> pom;
	y = pom;
	cout << "\nZ: ";
	cin >> pom;
	z = pom;
	printValues();
}

void Vector3D::printValues()const{
	printf("[%f %f %f]\n",getX(), getY(), getZ());
}

void Vector3D::swapVectros(Vector3D a, Vector3D b){
	Vector3D pom;
	pom = a;
	a = b;
	b = pom;
}

double Vector3D::operator *()const {
	Vector3D vec;
	double res;
	res = vec.x * x + vec.y * y + vec.z * z;
	return res;
}

Vector3D Vector3D::operator +()const {
	Vector3D vec;
	vec.x = x+x;
	vec.y = y+y;
	vec.z = z+z;
	return vec;
}