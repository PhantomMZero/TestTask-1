#pragma once

#include <cmath>
#include <vector>

#include "AtmosphericParametersTable.h"

class Projectile {
public:
	Projectile();
	void calculate();
	void setGr(double inputGr);//Ввод градусов
	void setV0(double inputV0);//Ввод начальной скорости
	void setLength(double inputLength);//Ввод длины снаряда
	void setDiameter(double inputDiameter);//Ввод диаметра снаряда
	//double getSpeedOfProjectile(int t);//Определение скорости тела
	//double getCoordinatesOnTrajectory(int t);//Определение координат тела с секундной точностью
	double getCoordinatesOfDestination();//Определение точки падения
	// getMass 1. Двигатель включен, 2. Двигатель выключен
	void exportToXls();
private:
	AtmosphericParameters atmParameters;
	void calculateAirResistanceForce(double height, double V);//Вычисление силы сопротивления воздуха
	void calculateSCrossSectionalArea(double d);//Вычисление площади сечения объекта
	double calculateTeta(double teta1, double V1);//Вычисление угла
	double calculateV(double teta1, double V1);//Вычисление скорости
	double calculateX(double x1, double teta1, double V1);//Вычисление координаты X
	double calculateY(double y1, double teta1, double V1);//Вычисление координаты Y
	double x0=0;//x start coordinate
	double y0=0;//y start coordinate
	double xOfDestination=0;
	double yOfDestination=0;
	double gr = 45; //degree
	double rad = gr * 3.14 / 180;
	double dt = 0.01;
	double V0 = 700; // m/s initial velocity
	//double VX = V0 * cos(rad);//start speed
	//double VY = V0 * sin(rad);//start speed
	// double z=0;//z coordinate
	double sCSA = 0;//Площадь сечения объекта (считается как площадь круга)
	double g = 9.8; //settled average value acceleration of free fall
	double d = 120; //diameter in millimeters
	double l = 600; //length in millimeters
	double lk = 120; //length of conical part in millimeters
	double PAir = 0; //Плотность воздуха рассчитывается в функции findAirDensity
	//Пересчитать массу
	double mass = 45.84; //kg mass of projectile mass of conical 3 + mass of cylinder 42 !hardcode	
	double c = 0.05;//Коэффициент сопротивления воздуха
	//SПоп. сеч
	double fAirResistance = 0;//Сопротивление воздуха (Рассчитывается в функции calculateAirResistanceForce)
	
	//double k = ((c * PAir * 3.14 * pow((d / 2)/1000, 2))/(2*mass)); //coef of resistance
	//k переделать F
	double P = 7800; //steel density kg/m3 not using because of hardcode
	std::vector<std::vector<double>> trajectory; //{ x1, y1, V1, t }
	
};