#include "stdafx.h"
#include "iostream"

const int ARGUMENTS_COUNT = 3;
const int RADIUS = 1;

using namespace std;

bool ValidateInput(int argc)
{
	if (argc != ARGUMENTS_COUNT)
	{
		cout << "Invalid arguments count." << endl;
		return false;
	}
	return true;
}

int GetIncomingPoints(int iterations)
{
	int result = 0;
	double x = 0;
	double y = 0;
	int minX = -RADIUS;
	int maxX = RADIUS;
	for (int i = 0; i < iterations; i++)
	{
		x = (double)rand() / (double)RAND_MAX * (maxX - minX) + minX;
		y = (double)rand() / (double)RAND_MAX * (maxX - minX) + minX;
		if (pow(x, 2) + pow(y, 2) <= pow(RADIUS, 2))
		{
			result++;
		}
	}
	return result;
}

double GetPiValue(int iterations)
{
	int incomingPoints = GetIncomingPoints(iterations);
	return (double)4 * incomingPoints / iterations;
}

int main(int argc, char* argv[])
{
	if (!ValidateInput(argc))
	{
		return 1;
	}
	int iterations = atoi(argv[1]);
	cout << GetPiValue(iterations) << endl;
	return 0;
}

