#include "stdafx.h"
#include "ThreadsController.h"
#pragma once
class CMonteCarlo
{
public:
	CMonteCarlo(size_t numberOfIterations, size_t numberOfThreads);
	~CMonteCarlo() = default;
	void Calculate();
	double GetPiValue() const;
private:
	static DWORD WINAPI CMonteCarlo::CalculateIncomingPoints(LPVOID data);

	CThreadsController m_controller;

	size_t m_numberOfInnerPoint = 0;
	size_t m_numberOfIterations = 0;
	size_t m_numberOfThreads = 0;
	double m_pi = 0;
};