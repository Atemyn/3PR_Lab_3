#include "mysource.h"

int main()
{
	// ����������� �������� ����������� �����.
	SetConsoleCP(1251);
	// ����������� �������� ����������� ������.
	SetConsoleOutputCP(1251);

	Building firstStaticB, secondStaticB;
	//Building* dynamicB = new Building;

	cout << "��������� �� �������� ������." << endl << "��� ��������� ������ �������� � ������." << endl << endl;

	firstStaticB.inputBuilding();
	secondStaticB.initBuilding();

	firstStaticB.addToBuilding(secondStaticB);

	firstStaticB.addFloors();
	firstStaticB.removeFloors();
}
