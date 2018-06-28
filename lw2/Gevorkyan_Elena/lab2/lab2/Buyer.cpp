#include "stdafx.h"
#include "Buyer.h"
#include "Departament.h"
#include "ThreadHandler.h"

static const size_t SLEEPING_TIME = 2000;

void ShoppingProcess(ThreadData & threadData)
{
	int cashNumber = rand() % 3;
	int idBuyer = threadData.number;
	std::cout << idBuyer << " покупатель ходит по отделам" << std::endl;
	Sleep(rand() % SLEEPING_TIME + SLEEPING_TIME);
	threadData.departaments.at(cashNumber).Lock();
	std::cout << idBuyer << " покупатель оплачивает покупку в отделе номер " << cashNumber << std::endl;
	Sleep(rand() % SLEEPING_TIME + SLEEPING_TIME);
	std::cout << idBuyer << " покупатель уходит из отдела номер " << cashNumber << std::endl;
	threadData.departaments.at(cashNumber).Unlock();
}

static DWORD WINAPI Shopping(LPVOID data)
{
	ThreadData* threadData = static_cast<ThreadData*>(data);
	std::srand(time(0));
	while (true)
	{
		ShoppingProcess(*threadData);
	}
	return 0;
}