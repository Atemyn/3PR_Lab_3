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

	/*void setBuiling(float b_sideLength, float b_basementHeight, float b_floorHeight, unsigned b_floorAmount, b_stabilityFactor)
	{
		if (b_sideLength > 0.0 && b_basementHeight > 0.0 && b_floorHeight > 0.0 && b_floorAmount > 0)
		{
			float b_stabilityFactor;
			b_stabilityFactor = (float)(b_sideLength * b_sideLength * sqrt(b_basementHeight)) / (b_floorHeight * b_floorAmount);
			if (b_stabilityFactor >= 1.0)
			{
				sideLength = b_sideLength;
				basementHeight = b_basementHeight;
				floorHeight = b_floorHeight;
				floorAmount = b_floorAmount;
				stabilityFactor = b_stabilityFactor;
				cout << "������ � ������������� ������������, ������ " << b_stabilityFactor << "���������!" << endl << endl;
			}
			else
				cout << "���������� ������������ ������ ������ �������: " << b_stabilityFactor << ". ������ ������� �����������, ��������� �� �������!" << endl << endl;
		}
		else
			cout << "��������� ������ �����������: ����� ��������� ������ ���� �����, ������� ��� ������ ����." << endl << endl;
	}*/

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



};
