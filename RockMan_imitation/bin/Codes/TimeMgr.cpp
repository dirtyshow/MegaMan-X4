#include "stdafx.h"
#include "TimeMgr.h"


void CTimeMgr::InitTimeMgr(void)
{
	QueryPerformanceCounter(&m_FrameTime);
	QueryPerformanceCounter(&m_FixTime);
	QueryPerformanceCounter(&m_LastTime);
	QueryPerformanceFrequency(&m_CpuTick); // 1�ʿ� cpu�� �� �� �ִ� ����ð�
}

void CTimeMgr::SetTime(void) // ������ ���� ȣ��ȴ�.
{
	QueryPerformanceCounter(&m_FrameTime); // ������ ���� ���ŵȴ�. ������ ���� �� ���ڰ� �Էµȴ�.
	if (m_FrameTime.QuadPart - m_LastTime.QuadPart > m_CpuTick.QuadPart) // �� ������ ������ ���� ��ĥ ������ 1�ʰ� �Ѿ������� �˻��Ѵ�. m_CpuTick���� 1�ʰ� ���ڴ�.
	{
		// 1�ʵ��� ������ ���ļ� ���� �ٽ� �޾ƿ´�.
		QueryPerformanceFrequency(&m_CpuTick); // ���� if���� ���� �簻�ſ���
		m_LastTime.QuadPart = m_FrameTime.QuadPart; // ���� ������ Frame Ÿ���� �� Last Ÿ���� �Ǵ� Last�� �־�д�.
	}

	m_fTime = float(m_FrameTime.QuadPart - m_FixTime.QuadPart) / m_CpuTick.QuadPart; //������ ������ ������ ���� �ʱ� ������ �ð����� �ٲ��ֱ� ������ �� �� ���� ���ϱ�� ����
	
	m_FixTime = m_FrameTime;
	
	/*
	if(DeltaTick - LastTick > GET_SINGLE(CTimeMgr)->GetTime()){
		// TODO: SOMETHING
	}

	*/
}

CTimeMgr::CTimeMgr()
{
}


CTimeMgr::~CTimeMgr()
{
}
