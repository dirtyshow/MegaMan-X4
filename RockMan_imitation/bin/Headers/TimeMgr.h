#pragma once
#include "Include.h"

class CTimeMgr
{
	DECLARE_SINGLETON(CTimeMgr)
private:
	LARGE_INTEGER m_FrameTime;
	LARGE_INTEGER m_FixTime;
	LARGE_INTEGER m_LastTime;
	LARGE_INTEGER m_CpuTick;
	float m_fTime;
public:
	float GetTime(void) const {
		return m_fTime;
	}
public:
	void InitTimeMgr(void); //ó���� ������ �� �� ȣ��
	void SetTime(void); //������ ���� ȣ�� (MainGame ���ư��°��� ��ġ�صθ� ����)
private:
	CTimeMgr();
public:
	~CTimeMgr();
};

