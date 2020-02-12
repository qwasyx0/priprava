#pragma once
struct Objekt {
public:
	Objekt(int id);
	double getX() const;
	double getY()const;
	void setY(double);
	void setX(double);
	int getId() const ;
	virtual ~Objekt() { };
private:
	int id;
	double x;
	double y;
};

