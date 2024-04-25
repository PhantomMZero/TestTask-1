#pragma once

#include <cmath>
#include <vector>

#include "AtmosphericParametersTable.h"

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
	AtmosphericParameters atmParameters;
	void calculateAirResistanceForce(double height, double V);//���������� ���� ������������� �������
	void calculateSCrossSectionalArea(double d);//���������� ������� ������� �������
	double calculateTeta(double teta1, double V1);//���������� ����
	double calculateV(double teta1, double V1);//���������� ��������
	double calculateX(double x1, double teta1, double V1);//���������� ���������� X
	double calculateY(double y1, double teta1, double V1);//���������� ���������� Y
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
	double sCSA = 0;//������� ������� ������� (��������� ��� ������� �����)
	double g = 9.8; //settled average value acceleration of free fall
	double d = 120; //diameter in millimeters
	double l = 600; //length in millimeters
	double lk = 120; //length of conical part in millimeters
	double PAir = 0; //��������� ������� �������������� � ������� findAirDensity
	//����������� �����
	double mass = 45.84; //kg mass of projectile mass of conical 3 + mass of cylinder 42 !hardcode	
	double c = 0.05;//����������� ������������� �������
	//S���. ���
	double fAirResistance = 0;//������������� ������� (�������������� � ������� calculateAirResistanceForce)
	
	//double k = ((c * PAir * 3.14 * pow((d / 2)/1000, 2))/(2*mass)); //coef of resistance
	//k ���������� F
	double P = 7800; //steel density kg/m3 not using because of hardcode
	std::vector<std::vector<double>> trajectory; //{ x1, y1, V1, t }
	
};