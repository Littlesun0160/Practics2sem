#include <iostream>
#include "KinematicSolver.hpp"

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "������� ����� ������� L1 � L2\n";
	float L1; float L2;
	std::cin >> L1 >> L2;
	KinematicSolver Robot1(L1, L2);
	std::cout << "������� ���������� �����\n";
	float X; float Y;
	std::cin >> X >> Y;
	Coordinate coo1(X, Y);
	coo1.GetAlphaBeta(Robot1);

	std::cout << "��� ������� ������ � ������� ������� L1 = " << L1 << " � L2 = " << L2 << " � ������ ���������� (" << X << " , " << Y << ") ���� ����� � ����� �������������� �����: " << coo1.GetAlpha() << " " << coo1.GetBeta();

}