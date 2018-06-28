#include "stdafx.h"
#include "Cashbox.h"


Cashbox::Cashbox()
	:
	m_mutex(CreateMutex(NULL, FALSE, NULL))
{
}

void Cashbox::Lock()
{
	WaitForSingleObject(m_mutex, INFINITE);
}

void Cashbox::Unlock()
{
	ReleaseMutex(m_mutex);
}

