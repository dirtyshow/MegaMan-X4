#include "stdafx.h"
#include "CollisionMgr.h"


void CCollisionMgr::RenderCollision()
{
	// ȣ��Ǹ� ��Ʈ �ڽ��� ������Ŵ.
	RECT hitBox[4];
	hitBox[0] = {
		-10, 430, 1500, 600
	}; // ���� �Ʒ� ����
	hitBox[1] = {
		
	};
	hitBox[2] = {
		-10, 100, 300, 270
	};
	hitBox[3] = {
		800, 100, 1000, 270
	};
}

CCollisionMgr::CCollisionMgr()
{
}


CCollisionMgr::~CCollisionMgr()
{
}
