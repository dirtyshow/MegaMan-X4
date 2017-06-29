#pragma once
#include "DynamicObjects.h"
class CPlayer :
	public CDynamicObjects
{
public:
	virtual HRESULT Initialize();
	virtual HRESULT Progress();
	virtual HRESULT Render();
	virtual HRESULT Release();
public:
	CPlayer();
	virtual ~CPlayer();
};
