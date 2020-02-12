#pragma once
class Vector3D
{
private:
	double x;
	double y;
	double z;
public:
	Vector3D();
	Vector3D(double _ax, double _ay, double _az) { x=_ax; y=_ay; z=_az;};
	~Vector3D();
	double getX()const { return x;};
	double getY()const { return y;};
	double getZ()const { return z;};
	void set(double _ax, double _ay, double _az);
	void readValues();
	void printValues()const;
	void swapVectros(Vector3D a, Vector3D b);
	double operator *()const;
	Vector3D operator +()const;
};

