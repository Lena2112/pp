#pragma once
class Cashbox
{
public:
	Cashbox();
	~Cashbox() = default;

	void Lock();
	void Unlock();
private:
	HANDLE m_mutex;
};

