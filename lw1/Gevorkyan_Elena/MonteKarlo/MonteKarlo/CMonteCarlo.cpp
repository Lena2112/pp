#include "stdafx.h"
#include "CMonteCarlo.h"
#include <cstdlib>
const int RADIUS = 1;

CMonteCarlo::CMonteCarlo(size_t numberOfIterations, size_t numberOfThreads)
	: m_numberOfIterations(numberOfIterations)
	, m_numberOfThreads(numberOfThreads)
{
	std::srand(time(0));
}

double CMonteCarlo::GetPiValue() const
{
	return m_pi;
}

void CMonteCarlo::Calculate()
{
	size_t numberOfIterationsAtThread = m_numberOfIterations / m_numberOfThreads;
	ThreadData data(numberOfIterationsAtThread, &m_numberOfInnerPoint);

	if (m_numberOfThreads == 1)
	{
		CalculateIncomingPoints(&data);
	}
	else
	{
		std::vector<ThreadData> threadsData = std::vector<ThreadData>(m_numberOfThreads, data);
		size_t remainingIterations = m_numberOfIterations % m_numberOfThreads;

		for (size_t i = 0; i < remainingIterations; ++i)
		{
			++(threadsData.at(i).numberOfIterations);
		}
		for (size_t i = 0; i < m_numberOfThreads; ++i)
		{
			if (threadsData.at(i).numberOfIterations != 0)
			{
				m_controller.AddThread(CalculateIncomingPoints, &threadsData.at(i));
			}
		}
		m_controller.Execute();
	}
	m_pi = (double)4 * m_numberOfInnerPoint / m_numberOfIterations;
}

DWORD CMonteCarlo::CalculateIncomingPoints(LPVOID data)
{
	float x;
	float y;
	int minX = -RADIUS;
	int maxX = RADIUS;
	ThreadData* threadData = static_cast<ThreadData*>(data);
	for (size_t i = 0; i < threadData->numberOfIterations; ++i)
	{
		x = (double)rand() / (double)RAND_MAX * (maxX - minX) + minX;
		y = (double)rand() / (double)RAND_MAX * (maxX - minX) + minX;
		if (pow(x, 2) + pow(y, 2) <= pow(RADIUS, 2))
		{
			InterlockedIncrement(threadData->numberOfInnerPoints);
		}
	}
	return 0;
}