#pragma once
#include "Include.h"
// ���⼭ ���ǿ� ���� Status ���� ������ ���ش�.
class CMonster;
class CPlayer;
class CCollisionMgr
{
	DECLARE_SINGLETON(CCollisionMgr)
public:
	vector<CMonster*>* pVector;
	void SetPointer(vector<CMonster*>* _param)
	{
		pVector = _param;
	}
	void CollisionCheck(CPlayer* pPlayer);
	void AttackandMop(RECT src);
public:
	CCollisionMgr();
	~CCollisionMgr();
};

