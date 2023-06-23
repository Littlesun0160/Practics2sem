#pragma once
#include <iostream>
#include <cmath>

class KinematicSolver
{
private:
	const float CoordinateXOfA = 0; const float CoordinateYOfA = 0;
	float LengthOfL1; float LengthOfL2;
	float alpha; float beta;
public:
	KinematicSolver(float L1, float L2)
	{
		if (L1 > 0 || L2 > 0)
		{
			LengthOfL1 = L1;
			LengthOfL2 = L2;
		}
		else { std::cout << "Ошибка: Длины шарниров должны быть положительными\n"; }
	}
	~KinematicSolver() {}

	void Solve(float CoordinateXOfC, float CoordinateYOfC)
	{
		float L = sqrt(pow(CoordinateXOfC, 2) + pow(CoordinateYOfC, 2));
		if (L < (LengthOfL1 + LengthOfL2))
		{
			const double PI = acos(-1);
			float q1; float q2;
			q1 = acos(CoordinateXOfC / L); //т.к. CoordinateXofC = L * cos(q1)
			q2 = acos((pow(LengthOfL1, 2) - pow(LengthOfL2, 2) + pow(L, 2)) / (2 * L * LengthOfL1)); //по Теореме косинусов a^2=b^2+c^2-2bc*cos(A)
			alpha = q1 - q2; 
			alpha = (alpha * 180) / PI;
			beta = PI - acos((pow(LengthOfL1, 2) + pow(LengthOfL2, 2) - pow(L, 2)) / (2 * LengthOfL1 * LengthOfL2));
			beta = (beta * 180) / PI;
		}
		else
		{
			std::cout << "Ошибка: Робот не может дотянуться до данной точки!\n";
		}
	}

	float GetAlpha()
	{
		return alpha;
	}
	float GetBeta()
	{
		return beta;
	}
};

class Coordinate
{
private:
	float alpha; float beta;
	float CoordinateXOfC; float CoordinateYOfC;
public:
	Coordinate(float X, float Y): CoordinateXOfC(X), CoordinateYOfC(Y) {}
	~Coordinate() {}

	void GetAlphaBeta(KinematicSolver Robot)
	{
		Robot.Solve(CoordinateXOfC, CoordinateYOfC);
		alpha = Robot.GetAlpha();
		beta = Robot.GetBeta();
	}

	float GetAlpha()
	{
		return alpha;
	}
	float GetBeta()
	{
		return beta;
	}
};