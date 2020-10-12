#pragma once
using namespace std;

#include <iostream>

class Building
{
private:
	// Длина стороны основания.
	float sideLength;
	// Высота фундамента.
	float basementHeight;
	// Высота этажа.
	float floorHeight;
	// Количество этажей.
	unsigned floorAmount;
	// Коэффициент устойчивости.
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
				cout << "Здание с коэффициентом стабильности, равным " << b_stabilityFactor << "построено!" << endl << endl;
			}
			else
				cout << "Коэффицинт стабильности здания меньше единицы: " << b_stabilityFactor << ". Здание слишком неустойчиво, постройка не удалась!" << endl << endl;
		}
		else
			cout << "Введенные данные некорректны: среди введенных данных есть числа, меньшие или равные нулю." << endl << endl;
	}*/

public:

	void getBuilding()
	{
		cout << "Свойства данного здания:" << endl;
		cout << "Длина стороны основания: " << sideLength << endl;
		cout << "Высота фундамента: " << basementHeight << endl;
		cout << "Высота этажа: " << floorHeight << endl;
		cout << "Количество этажей: " << floorAmount << endl;
		cout << "Коэффициент устойчивости: " << stabilityFactor << endl << endl;
	}

	void inputBuilding()
	{}


};
