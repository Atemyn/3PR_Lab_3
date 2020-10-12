#pragma once
using namespace std;

#include <iostream>

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

	void inputBuilding()
	{}


};
