#pragma once
// ���⼭ ���ǿ� ���� Status ���� ������ ���ش�.
class CCollisionMgr
{
	DECLARE_SINGLETON(CCollisionMgr)
public:
	void RenderCollision();
public:
	CCollisionMgr();
	~CCollisionMgr();
};

