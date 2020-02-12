#include "Vlak.h"

int main() {

	Vlak *pole[8];

	Osobni* os1 = new Osobni("OS35", 170, "7:30", "7:45");
	Osobni* os2 = new Osobni("OS567", 149, "9:37", "9:55");
	Rychlik* r1 = new Rychlik("R84", true, "6:15", "6:25");
	Rychlik* r2 = new Rychlik("R22", false, "12:05", "12:13");
	EuroCity* ec1 = new EuroCity("EC67", false, "8:57", "9:12");
	EuroCity* ec2 = new EuroCity("EC498", true, "18:44", "18:56");
	Nakladni* n1 = new Nakladni("N7894", Nakladni::CHEMICKY, "15:37", "15:57");
	Nakladni* n2 = new Nakladni("N68", Nakladni::POSTA, "20:08", "20:35");

	pole[0] = os1;
	pole[1] = os2;
	pole[2] = r1;
	pole[3] = r2;
	pole[4] = ec1;
	pole[5] = ec2;
	pole[6] = n1;
	pole[7] = n2;

	for (int i=0; i<8; i++) {
		pole[i]->toString();
	}

	Osobni* os3;

	//os3 = (*os1).operator+(*os2);
	os3 = (*os1)+(*os2); 
	cout << "\nOperator +\n";
	os3->toString();

	system("pause");
	return 0;

}