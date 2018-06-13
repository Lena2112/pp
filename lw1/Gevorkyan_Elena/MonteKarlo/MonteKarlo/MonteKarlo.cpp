#include "stdafx.h"
#include "iostream"
#include "CMonteCarlo.h"

const int ARGUMENTS_COUNT = 3;

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

int main(int argc, char* argv[])
{
	if (!ValidateInput(argc))
	{
		return 1;
	}
	int iterations = atoi(argv[1]);
	int threads = atoi(argv[2]);
	if (threads > 64 || threads < 1)
	{
		cout << "Invalid thread count" << endl;
		return 1;
	}
	if (iterations < 0)
	{
		cout << "Invalid iteration count" << endl;
		return 1;
	}

	CMonteCarlo monteCarlo(iterations, threads);
	clock_t start = clock();
	monteCarlo.Calculate();
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "Pi: " << monteCarlo.GetPiValue() << endl << "Time: " << seconds << endl;
	return 0;
}

