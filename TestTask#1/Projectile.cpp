#include "Projectile.h"
#include "Table.h"

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
	//Конечно-разностная аппроксимация
	double V1, x1, y1, t, V2, x2, y2, teta1, teta2; 
	x1 = 0;
	y1 = 0;
	V1 = V0;
	t = 0;
	teta1 = rad;
	trajectory.push_back({ x1, y1, V1, t });
	while (true) {
		V2 = V1 - dt * (k * pow(V1, 2) + g * sin(teta1));
		teta2 = teta1 - dt * g * cos(teta1) / V1;
		x2 = x1 + (V1 * cos(teta1)) * dt;
		y2 = y1 + (V1 * sin(teta1)) * dt;
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

void Projectile::exportToXls()
{
	std::fstream fout;

	// opens an existing csv file or creates a new file. 
	fout.open("results.csv", std::ios::out | std::ios::app);
	fout << "Column0,Column1,Column2,Column3\n";

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
