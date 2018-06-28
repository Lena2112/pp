#include "stdafx.h"
#include "Cashbox.h"
#include "ThreadHandler.h"
#pragma once
static const size_t SLEEPING_TIME = 2000;


class CBuyer
{
public:
	CBuyer() = default;
	~CBuyer() = default;
};

void ShoppingProcess(ThreadData & threadData)
{
	int cashNumber = rand() % 3;
	int idBuyer = threadData.number + 1;
	printf("%d ���������� ����� �� �������\n", idBuyer);
	Sleep(rand() % SLEEPING_TIME + SLEEPING_TIME);
	threadData.cashboxs.at(cashNumber).Lock();
	printf("%d ���������� ���������� ������� � ������ ����� %d\n", idBuyer, cashNumber + 1);
	Sleep(rand() % SLEEPING_TIME + SLEEPING_TIME);
	printf("%d ���������� ������ �� ������ ����� %d\n", idBuyer, cashNumber + 1);
	threadData.cashboxs.at(cashNumber).Unlock();
}

static DWORD WINAPI Shopping(LPVOID data)
{
	ThreadData* threadData = static_cast<ThreadData*>(data);
	std::srand(time(0) * threadData->number);
	while (true)
	{
		ShoppingProcess(*threadData);
	}
	return 0;
}