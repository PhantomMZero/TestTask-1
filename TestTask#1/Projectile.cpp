#include "Projectile.h"

#include <iostream>
#include <fstream>


//Тело цилиндро-конической формы диаметром d, равным 120 мм, 
// длиной l, равной 600 мм, с длиной конической части, 
// равной диаметру тела, изготовленное из конструкционной стали, 
// запускается из баллистической установки со скоростьюV0, равной 700 м/сек. 
// Ствол баллистической установки расположен под углом 45° к горизонту.


//Что требуется определить :
//1.	Определить траекторные параметры тела
// (скорость тела, координаты тела на траектории с произвольной дискретностью, 
// обеспечивающей возможность графического построения линии траектории).
//2.	Определить координаты точки падения тела на Землю

//Подъемная сила 0
//Тяга 0

Projectile::Projectile()
{

}

void Projectile::calculate()
{
	calculateSCrossSectionalArea(d);
	//Конечно-разностная аппроксимация
	double V1, x1, y1, t, V2, x2, y2, teta1, teta2;
	x1 = 0;
	y1 = 0;
	V1 = V0;
	t = 0;
	teta1 = rad;
	trajectory.push_back({ x1, y1, V1, t });
	while (true) {
		calculateAirResistanceForce(y1, V1);
		g=atmParameters.findAccelerationOfFreeFall(y1);
		V2 = calculateV(teta1, V1);
		teta2 = calculateTeta(teta1, V1);
		x2 = calculateX(x1,teta1, V1);
		y2 = calculateY(y1, teta1, V1);
		t = t + dt;
		trajectory.push_back({ x2, y2, V2, t });
		if (y2 <= 0) {
			xOfDestination = x2;
			std::cout << "V= " << V2 << "m/s\n";
			std::cout << "x= " << x2 << "m\n";
			std::cout << "t= " << t << "sec\n";
			break;
		}
		V1 = V2;
		teta1 = teta2;
		x1 = x2;
		y1 = y2;
	}
}

void Projectile::setGr(double inputGr)
{
	gr = inputGr;
}

void Projectile::setV0(double inputV0)
{
	V0 = inputV0;
}

void Projectile::setLength(double inputLength)
{
	l = inputLength;
}

void Projectile::setDiameter(double inputDiameter)
{
	d = inputDiameter;
}

void Projectile::setMass(double mass)
{
	this->mass = mass;
}


void Projectile::calculateAirResistanceForce(double height, double V) //Расчет силы сопротивления воздуха
{
	fAirResistance = (c * atmParameters.findAirDensity(height) * pow(V, 2) * sCSA)/2;
}

void Projectile::calculateSCrossSectionalArea(double d)
{
	sCSA = 3.14 * pow(((d / 1000) / 2), 2);
}

double Projectile::calculateTeta(double teta1, double V1)
{
	return teta1 - dt * g * cos(teta1) / V1;
}

double Projectile::calculateV(double teta1, double V1)
{
	return V1 - dt * (fAirResistance/mass + g * sin(teta1));
}

double Projectile::calculateX(double x1, double teta1, double V1)
{
	return x1 + (V1 * cos(teta1)) * dt;
}

double Projectile::calculateY(double y1, double teta1, double V1)
{
	return y1 + (V1 * sin(teta1)) * dt;
}



void Projectile::exportToXls()
{
	std::fstream fout;

	// opens an existing csv file or creates a new file. 
	fout.open("results.csv", std::ios::out | std::ios::app);
	fout << "x,y,V,t\n";

	for (int i = 0; i < trajectory.size(); ++i) {
		fout << trajectory[i][0] << ','
			<< trajectory[i][1] << ','
			<< trajectory[i][2] << ','
			<< trajectory[i][3] << '\n';
	}


}




//double Projectile::getSpeedOfProjectile(int t)
//{
//	return 0;
//}

//double Projectile::getCoordinatesOnTrajectory(int t)
//{
//	return 0;
//}

double Projectile::getCoordinatesOfDestination()
{
	if (xOfDestination!=0) return xOfDestination;
}
