#pragma once
using namespace std;

#include <iostream>
#include <conio.h>

class Building
{
private:
	// ����� ������� ���������.
	float sideLength;
	// ������ ����������.
	float basementHeight;
	// ������ �����.
	float floorHeight;
	// ���������� ������.
	unsigned floorAmount;
	// ����������� ������������.
	float stabilityFactor;

	void setBuiling(float b_sideLength, float b_basementHeight, float b_floorHeight, unsigned b_floorAmount, float b_stabilityFactor)
	{
		sideLength = b_sideLength;
		basementHeight = b_basementHeight;
		floorHeight = b_floorHeight;
		floorAmount = b_floorAmount;
		stabilityFactor = b_stabilityFactor;
	}

public:

	void getBuilding()
	{
		cout << "�������� ������� ������:" << endl;
		cout << "����� ������� ���������: " << sideLength << endl;
		cout << "������ ����������: " << basementHeight << endl;
		cout << "������ �����: " << floorHeight << endl;
		cout << "���������� ������: " << floorAmount << endl;
		cout << "����������� ������������: " << stabilityFactor << endl << endl;
	}

	void initBuilding()
	{
		setBuiling(1.0, 1.0, 1.0, 1, 1.0);
	}

	void inputBuilding()
	{
		// ������ �� ������ ��� ����� ���� ����������� ������.
		cout << "������� ����� ������� ������ ������: ";
		while (!(cin >> sideLength) || sideLength <= 0)
		{
			cout << "�������� ���� ����� ������� - ��� ������ ���� ������������� ������. ���������� ��� ���: ";
			cin.clear();
		}

		cout << "������� ������ ���������� ������ ������: ";
		while (!(cin >> basementHeight) || basementHeight <= 0)
		{
			cout << "�������� ���� ������ ���������� - ��� ������ ���� ������������� ������. ���������� ��� ���: ";
			cin.clear();
		}

		cout << "������� ������ ������ ����� ������ ������: ";
		while (!(cin >> floorHeight) || floorHeight <= 0)
		{
			cout << "�������� ���� ������ ����� - ��� ������ ���� ������������� ������. ���������� ��� ���: ";
			cin.clear();
		}

		cout << "������� ���������� ������ ������ ������: ";
		while (!(cin >> floorAmount) || floorAmount <= 0)
		{
			cout << "�������� ���� ���������� - ��� ������ ���� ������������� ����� ������. ���������� ��� ���: ";
			cin.clear();
		}
		// ������ ����������� ������������.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		// ���� ����������� ������������ ������ 1 - ������ ������; ��������� ��������� ���� �������������
		if (stabilityFactor < 1.0)
		{
			cout << "����������� ������������ ������ ������ k = " << stabilityFactor << " ������ �������. ��� ����� ������� � ������ �� ������. ������ �� ����������� ���?" << endl;
			cout << "���� ��� - ������� Esc, ���� �� - ����� ������ ������." << endl << endl;
			if (_getch() != 27)
			{
				inputBuilding();
			}
			else
			{
				cout << "������ �� ������ ������� � �������!" << endl << endl << endl;
				initBuilding();
			}
		}
		else
		{
			cout << "�������! ������ ���������� ���������� � ������������� ������������ k = " << stabilityFactor << "." << endl << endl << endl;
		}
	}

	void addToBuilding(Building build)
	{
		cout << "��������� ��� ������... �� �������� �����:" << endl;
		cout << "����� ������ ���������: " << sideLength << " � " << build.sideLength << endl <<
			"������ �����������: " << basementHeight << " � " << build.basementHeight << endl << "������ ������: " << floorHeight << " � " << build.floorHeight << endl <<
			"���������� ������: " << floorAmount << " � " << build.floorAmount << endl << "������������ ������������: " << stabilityFactor << " � " << build.stabilityFactor << endl << endl;

		if (sideLength < build.sideLength)
			sideLength = build.sideLength;

		if (basementHeight < build.basementHeight)
			basementHeight = build.basementHeight;

		if (floorHeight < build.floorHeight)
			floorHeight = build.floorHeight;

		floorAmount = floorAmount + build.floorAmount;
		// ������ ������ ������������ ������������ � �������� ��� ������������.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		if (stabilityFactor < 1)
		{
			cout << "� ���������, ����� ���������� ���� ������ ����� ������ ����� �� �����������, ��� ��� ��� ����������� ������������ k = " << stabilityFactor << " ������ ����." << endl << endl;
			initBuilding();
		}
		else
		{
			cout << "�������! ����� ������ �������. ��� �������� �����:" << endl << endl;
			getBuilding();
		}
	}

	void addFloors()
	{
		unsigned floorsToAdd;
		// ������ �� ������ ��� ����� floorsToAdd.
		cout << "������� ���������� ������ ��� ���������� � ������ ������: ";
		while (!(cin >> floorsToAdd) || floorsToAdd < 0)
		{
			cout << "�������� ���� ���������� - ��� ������ ���� ��������������� ����� ������. ���������� ��� ���: ";
			cin.clear();
		}

		floorAmount = floorAmount + floorsToAdd;
		// ������ ������ ������������ ������������ � �������� ��� ������������.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		if (stabilityFactor < 1.0)
		{
			cout << "����������� ������������ ������ ������ k = " << stabilityFactor << " ���� ������ �������. ��� ����� ������� � ������ �� ������. ���������� �������� ���������� ������ � ���������� (��������, �� 0)" << endl << endl;
			floorAmount = floorAmount - floorsToAdd;
			addFloors();
		}
		else
		{
			cout << "�������! ������ ���������� ���������� � ������������� ������������ k = " << stabilityFactor << endl << endl;
		}
		// ����������� ���������� � ������.
		getBuilding();
	}

	// ������� �� �������� floorsToRemove ������ � ���������� ��������� Building, �� ������ ��������� b.
	void removeFloors()
	{
		unsigned floorsToRemove;
		// ������ �� ������ ��� ����� floorsToRemove.
		cout << "������� ���������� ������ ��� �������� � ������ ������: ";
		while (!(cin >> floorsToRemove) || floorsToRemove < 0 || floorsToRemove >= floorAmount)
		{
			cout << "�������� ���� ���������� - ��� ������ ���� ��������������� ����� ������ � ������� ������ ����� ������. ���������� ��� ���: ";
			cin.clear();
		}
		// ������ ������ ������������ ������������.
		floorAmount = floorAmount - floorsToRemove;
		cout << "����� ������� �������!" << endl;
		// ����������� ���������� � ������.
		getBuilding();
	}

};
