#include "stdafx.h"
#include <iostream>
#include "Cashbox.h"
#include "Buyer.h"
#include "ThreadHandler.h"

std::vector<Cashbox> CreateCashboxs();
std::vector<ThreadData> CreateBuyers(std::vector<Cashbox> & cashboxs);
void ProcessingShopping(std::vector<ThreadData> & buyersData);

int main()
{
	std::ios_base::sync_with_stdio(true);
	setlocale(LC_ALL, "rus");
	std::vector<Cashbox> cashboxs = CreateCashboxs();
	std::vector<ThreadData> buyersData = CreateBuyers(cashboxs);
	ProcessingShopping(buyersData);
	return 0;
}

std::vector<Cashbox> CreateCashboxs()
{
	std::vector<Cashbox> result;
	for (size_t i = 0; i < 3; i++)
	{
		result.emplace_back(Cashbox());
	}
	return result;
}

std::vector<ThreadData> CreateBuyers(std::vector<Cashbox> & cashboxs)
{
	std::vector<ThreadData> result;
	for (size_t i = 0; i < 5; i++)
	{
		result.emplace_back(ThreadData(cashboxs, i));
	}
	return result;
}

void ProcessingShopping(std::vector<ThreadData> & buyersData)
{
	CThreadHandler handler;
	for (size_t i = 0; i < buyersData.size(); i++)
	{
		handler.Add(&buyersData.at(i), Shopping);
	}
	handler.Wait();
}