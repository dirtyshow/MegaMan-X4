#pragma once
#include "DynamicObjects.h"

class CTextureMgr;
class CPlayer :
	public CDynamicObjects
{
private:
	bool isControllActivated = false; // Ű���� �Է� Ȱ��ȭ (ó�� ������ ���� �ǰݽ� ��Ȱ��ȭ. ���ÿ� Ȱ��ȭ)
private:
	DIRECTION Pointer = D_RIGHT;
	CTextureMgr* pTextureMgr = nullptr;
private:
	float x, y;
	float m_fSpeed = 5.f;
public:
	void Transforming();
	void KeyCheck();
public:
	virtual HRESULT Initialize();
	virtual HRESULT Progress(); // Updates
	virtual HRESULT Render();
	virtual HRESULT Release();
public:
	CPlayer();
	virtual ~CPlayer();
};

