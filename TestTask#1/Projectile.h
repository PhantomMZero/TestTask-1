#pragma once

#include <cmath>
#include <vector>

class Projectile {
public:
	Projectile();
	void calculate();
	void setGr(double inputGr);//���� ��������
	void setV0(double inputV0);//���� ��������� ��������
	void setLength(double inputLength);//���� ����� �������
	void setDiameter(double inputDiameter);//���� �������� �������
	//double getSpeedOfProjectile(int t);//����������� �������� ����
	//double getCoordinatesOnTrajectory(int t);//����������� ��������� ���� � ��������� ���������
	double getCoordinatesOfDestination();//����������� ����� �������
	// getMass 1. ��������� �������, 2. ��������� ��������
	void exportToXls();
private:
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
	double g = 9.8; //settled average value acceleration of free fall
	double d = 120; //diameter in millimeters
	double l = 600; //length in millimeters
	double lk = 120; //length of conical part in millimeters
	double PAir = 1.29; //average air density 
	//����������� �����
	double mass = 45.84; //kg mass of projectile mass of conical 3 + mass of cylinder 42 !hardcode	
	
	double R = 0;// air resistance R=c*s(pV^2/2)
	//k=cSp/2m coef Air resistance in acceleration �=0,05
	double c = 0.05;
	//S���. ���
	double k = ((c * PAir * 3.14 * pow((d / 2)/1000, 2))/(2*mass)); //coef of resistance
	//k ���������� F
	double P = 7800; //steel density kg/m3 not using because of hardcode
	std::vector<std::vector<double>> trajectory; //{ x1, y1, V1, t }
	
};