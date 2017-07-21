#pragma once
#include "Include.h"
#include "Device.h"
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
	unsigned int Delta = GetTickCount();
	const LPD3DXSPRITE& RenderSprite = GET_SINGLE(CDevice)->GetSprite();
	void EffectsFade(const TEXINFO *rTexInfo, D3DXMATRIX &_matWorld,
		D3DXVECTOR3 &_vCenter, D3DXVECTOR3 &_vPosition);
public:
	void SingleRender(const TEXINFO *rTexInfo, D3DXMATRIX& _matWorld,
		D3DXVECTOR3 &_vCenter, D3DXVECTOR3 &_vPosition,
		SINGLE_RENDER_TYPE type, FRAME _frame);
	void MultiRender();
private:
	CRenderMgr();
public:
	~CRenderMgr();
};