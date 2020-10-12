#pragma once
using namespace std;

#include <iostream>
#include <conio.h>

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

	void initBuilding()
	{
		setBuiling(1.0, 1.0, 1.0, 1, 1.0);
	}

	void inputBuilding()
	{
		// Защиты от дурака для ввода всех необходимых данных.
		cout << "Введите длину стороны вашего здания: ";
		while (!(cin >> sideLength) || sideLength <= 0)
		{
			cout << "Неверный ввод длины стороны - она должна быть положительным числом. Попробуйте еще раз: ";
			cin.clear();
		}

		cout << "Введите высоту фундамента вашего здания: ";
		while (!(cin >> basementHeight) || basementHeight <= 0)
		{
			cout << "Неверный ввод высоты фундамента - она должна быть положительным числом. Попробуйте еще раз: ";
			cin.clear();
		}

		cout << "Введите высоту одного этажа вашего здания: ";
		while (!(cin >> floorHeight) || floorHeight <= 0)
		{
			cout << "Неверный ввод высоты этажа - она должна быть положительным числом. Попробуйте еще раз: ";
			cin.clear();
		}

		cout << "Введите количество этажей вашего здания: ";
		while (!(cin >> floorAmount) || floorAmount <= 0)
		{
			cout << "Неверный ввод количества - оно должно быть положительным целым числом. Попробуйте еще раз: ";
			cin.clear();
		}
		// Расчет коэффицента устойчивости.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		// Если коэффициент устойчивости меньше 1 - здание упадет; необхлдим повторный ввод характеристик
		if (stabilityFactor < 1.0)
		{
			cout << "Коэффициент стабильности вашего здания k = " << stabilityFactor << " меньше единицы. Оно может рухнуть с минуты на минуту. Хотите ли перестроить его?" << endl;
			cout << "Если НЕТ - нажмите Esc, если ДА - любую другую кнопку." << endl << endl;
			if (_getch() != 27)
			{
				inputBuilding();
			}
			else
			{
				cout << "Здание не смогло устоять и рухнуло!" << endl << endl << endl;
				initBuilding();
			}
		}
		else
		{
			cout << "Отлично! Здание получилось устойчивым с коэффициентом устойчивости k = " << stabilityFactor << "." << endl << endl << endl;
		}
	}

	void addToBuilding(Building build)
	{
		cout << "Совмещаем два здания... Их свойства такие:" << endl;
		cout << "Длины сторон оснований: " << sideLength << " и " << build.sideLength << endl <<
			"Высоты фундаментов: " << basementHeight << " и " << build.basementHeight << endl << "Высоты этажей: " << floorHeight << " и " << build.floorHeight << endl <<
			"Количества этажей: " << floorAmount << " и " << build.floorAmount << endl << "Коэффициенты устойчивости: " << stabilityFactor << " и " << build.stabilityFactor << endl << endl;

		if (sideLength < build.sideLength)
			sideLength = build.sideLength;

		if (basementHeight < build.basementHeight)
			basementHeight = build.basementHeight;

		if (floorHeight < build.floorHeight)
			floorHeight = build.floorHeight;

		floorAmount = floorAmount + build.floorAmount;
		// Расчет нового коэффициента устойчивости и проверка его корректности.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		if (stabilityFactor < 1)
		{
			cout << "К сожалению, после совмещения двух зданий новое здание сразу же развалилось, так как его коэффициент устойчивости k = " << stabilityFactor << " меньше нуля." << endl << endl;
			initBuilding();
		}
		else
		{
			cout << "Отлично! Новое здание устояло. Его свойства такие:" << endl << endl;
			getBuilding();
		}
	}

	void addFloors()
	{
		unsigned floorsToAdd;
		// Защита от дурака для ввода floorsToAdd.
		cout << "Введите количество этажей для добавления к вашему зданию: ";
		while (!(cin >> floorsToAdd) || floorsToAdd < 0)
		{
			cout << "Неверный ввод количества - оно должно быть неотрицательным целым числом. Попробуйте еще раз: ";
			cin.clear();
		}

		floorAmount = floorAmount + floorsToAdd;
		// Расчет нового коэффициента устойчивости и проверка его корректности.
		stabilityFactor = (float)(sideLength * sideLength * sqrt(basementHeight)) / (floorHeight * floorAmount);
		if (stabilityFactor < 1.0)
		{
			cout << "Коэффициент стабильности вашего здания k = " << stabilityFactor << " стал меньше единицы. Оно может рухнуть с минуты на минуту. Попробуйте изменить количество этажей к добавлению (например, на 0)" << endl << endl;
			floorAmount = floorAmount - floorsToAdd;
			addFloors();
		}
		else
		{
			cout << "Отлично! Здание получилось устойчивым с коэффициентом устойчивости k = " << stabilityFactor << endl << endl;
		}
		// Отображение информации о здании.
		getBuilding();
	}



};
