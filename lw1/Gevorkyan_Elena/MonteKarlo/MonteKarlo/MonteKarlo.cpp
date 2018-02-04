#include "stdafx.h"
#include "iostream"
#include <ctime>

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
	clock_t start = clock();
	if (!ValidateInput(argc))
	{
		return 1;
	}
	int iterations = atoi(argv[1]);
	double pi = GetPiValue(iterations);
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Pi: " << pi << endl << "Time: " << seconds << endl;
	return 0;
}

