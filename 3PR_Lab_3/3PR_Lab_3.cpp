#include "mysource.h"

int main()
{
	// Подключение русского консольного ввода.
	SetConsoleCP(1251);
	// Подключение русского консольного вывода.
	SetConsoleOutputCP(1251);

	Building firstStaticB, secondStaticB;
	//Building* dynamicB = new Building;

	cout << "Программа по созданию зданий." << endl << "Все размерные данные вводятся в метрах." << endl << endl;

	firstStaticB.inputBuilding();
	secondStaticB.initBuilding();

	firstStaticB.addToBuilding(secondStaticB);

	firstStaticB.addFloors();
	firstStaticB.removeFloors();
}
