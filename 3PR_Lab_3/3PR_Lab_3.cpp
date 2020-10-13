#include "mysource.h"

int main()
{
	// ����������� �������� ����������� �����.
	SetConsoleCP(1251);
	// ����������� �������� ����������� ������.
	SetConsoleOutputCP(1251);

	/* ������ �� ������������ ������������ ������. */
	Building firstStaticB, secondStaticB;

	cout << "��������� �� �������� ������." << endl << "��� ��������� ������ �������� � ������." << endl;
	cout << "����������� ����������: " << endl << endl;

	firstStaticB.inputBuilding();
	secondStaticB.initBuilding();

	firstStaticB.addToBuilding(secondStaticB);

	firstStaticB.addFloors();
	firstStaticB.removeFloors();
	/*............................................*/

	/* ������ � ������������� ������������ ������. */
	Building* firstDynamicB = new Building;
	Building* secondDynamicB;

	secondDynamicB = (Building*)malloc(sizeof(Building));

	cout << "������������ ����������: " << endl << endl;

	firstDynamicB->inputBuilding();
	secondDynamicB->initBuilding();

	firstDynamicB->addToBuilding(*secondDynamicB);

	firstDynamicB->addFloors();
	firstDynamicB->removeFloors();

	delete firstDynamicB;
	free(secondDynamicB);
	/*............................................*/

	/* ������������ ������ ��������. */
	int amount = 2;
	Building* firstDynamicArray = new Building[amount];
	Building* secondDynamicArray;

	cout << "������������ ������ ��������: " << endl << endl;

	firstDynamicArray->inputBuilding();
	(firstDynamicArray + 1)->initBuilding();

	firstDynamicArray->addToBuilding(*(firstDynamicArray + 1));

	// ������ ��� ��������� ������ �� ������ ��������.
	secondDynamicArray = (Building*)calloc(amount, sizeof(Building));
	if (secondDynamicArray != NULL)
	{
		secondDynamicArray = (Building*)realloc(secondDynamicArray, (amount + 2) * sizeof(Building));
		if (secondDynamicArray != NULL)
		{
			cout << "��������� ������� �������: " << endl;
			(secondDynamicArray + 3)->initBuilding();
			(secondDynamicArray + 3)->getBuilding();
		}
	}

	delete[] firstDynamicArray;
	free(secondDynamicArray);
	/*...............................*/

	return 0;
}
