#include "stdafx.h"
#pragma once
class Cashbox;

struct ThreadData
{
	std::vector<Cashbox> & cashboxs;
	int number;
	ThreadData(std::vector<Cashbox> & cashboxs, int number)
		: cashboxs(cashboxs),
		number(number)
	{
	}
};

class CThreadHandler
{
public:
	CThreadHandler() = default;
	~CThreadHandler();
	void Add(LPVOID data, LPTHREAD_START_ROUTINE function);
	void Wait();
private:
	std::vector<HANDLE> m_threads;
};