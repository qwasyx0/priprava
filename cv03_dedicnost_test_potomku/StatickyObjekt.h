#pragma once
enum TypPrekazky {
	Skala = 1,
	MalaRostlina = 2,
	VelkaRostlina = 3
};

struct StatickyObjekt : Objekt{
public:
	StatickyObjekt(int id, TypPrekazky typPrekazky);
	TypPrekazky getTypPrekazky();
private:
	TypPrekazky typPrekazky;
	StatickyObjekt();
};
