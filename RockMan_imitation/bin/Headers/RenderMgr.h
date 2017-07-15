#pragma once
#include "Include.h"
#include "Device.h"
/* UTF-Korean */
/*
Rendering Helper for each Sprite Mode; Single, Multi
��������Ʈ ��忡 ���� �������� �����ִ� �Ŵ���
�̱��϶�, ���� ��Ÿ�� ��ǥ�� �����ؼ� �����Ӻ��� �����̰� ���̰� �� �� �ִ�.
��Ƽ�϶�, �ൿ�� ���� �� ���� ������ŭ �����Ͽ� �����Ӻ��� �����̰� ���̰� �� �� �ִ�.
*/
class CRenderMgr
{
	DECLARE_SINGLETON(CRenderMgr)
private:
	const LPD3DXSPRITE& RenderSprite = GET_SINGLE(CDevice)->GetSprite();
public:
	void SingleRender(const TEXINFO*& pTexInfo, D3DXMATRIX& _matWorld,
		D3DXVECTOR3*& _vCenter, 
		D3DXVECTOR3*& _vPosition, SINGLE_RENDER_TYPE type, FRAME& _frame); // Option �ʿ���, �Ϲ������� ����(��ü) �ɼǿ� ���� ����
	void MultiRender();
private:
	CRenderMgr();
public:
	~CRenderMgr();
};