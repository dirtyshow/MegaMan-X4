#pragma once
// ũ��Ƽ�� �������� ���� ���μ����� ���� ���� �����带 �����ؼ� �����.
// ���� ������, Ű �Է�, Process() �Լ��� 3�� ���������� ���� Tick�� �ø� ����.
// ������Ʈ ���������� ���� ���ϰ� ȸ������� ���鶧�� ��Ƽ ������ (Lock-Free �˰��� �Ἥ (���ؽ� ��) ���� ��ȹ)
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

