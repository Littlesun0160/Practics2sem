#include <iostream>
#include "KinematicSolver.hpp"

int main()
{
	setlocale(LC_ALL, "rus");
	std::cout << "¬ведите длины звеньев L1 и L2\n";
	float L1; float L2;
	std::cin >> L1 >> L2;
	KinematicSolver Robot1(L1, L2);
	std::cout << "¬ведите координаты точки\n";
	float X; float Y;
	std::cin >> X >> Y;
	Coordinate coo1(X, Y);
	coo1.GetAlphaBeta(Robot1);

	std::cout << "ƒл€ данного робота с длинами звеньев L1 = " << L1 << " и L2 = " << L2 << " и данной координаты (" << X << " , " << Y << ") углы альфа и бетта соответственно равны: " << coo1.GetAlpha() << " " << coo1.GetBeta();

}