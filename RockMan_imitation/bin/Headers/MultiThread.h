#pragma once
// ũ��Ƽ�� �������� ���� ���μ����� ���� ���� �����带 �����ؼ� �����.
// ���� ������, Ű �Է�, Process() �Լ��� 3�� ���������� ���� Tick�� �ø� ����.
#include <thread>

class CMultiThread
{
private:
	CRITICAL_SECTION m_Critic; // ���� ��ü �޸�
public:
	void EnterCriticalSection();
public:
	CMultiThread();
	~CMultiThread();
};

