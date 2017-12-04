#pragma once
#include "Include.h"
#include "Device.h"
#include "TimeMgr.h"

/* UTF-Korean */
/*
Rendering Helper for each Sprite Mode; Single, Multi
��������Ʈ ��忡 ���� �������� �����ִ� �Ŵ���
�̱��϶�, ���� ��Ÿ�� ��ǥ�� �����ؼ� �����Ӻ��� �����̰� ���̰� �� �� �ִ�.
��Ƽ�϶�, �ൿ�� ���� �� ���� ������ŭ �����Ͽ� �����Ӻ��� �����̰� ���̰� �� �� �ִ�.
�ӵ������δ� �̱��� ���� ������. �޸𸮵� �� ��⵵ �Ѵ�. ��Ƽ�� �ϸ� ������ ���Ƽ�
���ҽ��� ���� �����ϰ� �θ��� �ָ��ϴ�. ������ �� ���ϴ� �������� ���� �� �ִٴ� ������ �ִ�.

*/
class CRenderMgr
{
	DECLARE_SINGLETON(CRenderMgr)
private:
	//float fDelta = GET_SINGLE(CTimeMgr)->GetTime();
	const LPD3DXSPRITE& RenderSprite = GET_SINGLE(CDevice)->GetSprite();
	void EffectsFade(const TEXINFO *rTexInfo, D3DXMATRIX &_matWorld,
		D3DXVECTOR3 &_vCenter, D3DXVECTOR3 &_vPosition);
public:
	void SingleRender(const TEXINFO *rTexInfo, D3DXMATRIX& _matWorld,
		D3DXVECTOR3 &_vCenter, D3DXVECTOR3 &_vPosition,
		SINGLE_RENDER_TYPE type, FRAME _frame);
	void MultiRender(const TEXINFO *rTexInfo, D3DXMATRIX _matWorld, MULTI_RENDER_TYPE type, int& cnt);
private:
	CRenderMgr();
public:
	~CRenderMgr();
};