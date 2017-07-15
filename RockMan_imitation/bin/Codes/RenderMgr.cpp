#	include "stdafx.h"
#include "RenderMgr.h"


CRenderMgr::CRenderMgr()
{
}


CRenderMgr::~CRenderMgr()
{
}

// ������Ʈ�� �� ������ ������.
// 1. �� ĳ���ʹ� ���� ������Ʈ
// 2. ������ ������ ������Ʈ
// 3. �� �˻�� �� ������(�ִϸ��̼��� ȣ��Ǵ°��̸� ȣ��)���� �˻��ϰ� �ȴ�.



void CRenderMgr::SingleRender(const TEXINFO*& pTexInfo, D3DXMATRIX& _matWorld, 
	D3DXVECTOR3*& _vCenter, D3DXVECTOR3*& _vPosition, SINGLE_RENDER_TYPE type, FRAME& _frame)
{
	//_vPosition->x *= _frame;
	//_vPosition->y *= _frame;
	switch (type)
	{
	case E_SINGLE_RENDER_TYPE_STRAIGHT:
		RenderSprite->SetTransform(&_matWorld);
		RenderSprite->Draw(pTexInfo->pTexture, NULL,
			_vCenter, _vPosition, D3DCOLOR_ARGB(255, 0, 0, 0));
		break;
	case E_SINGLE_RENDER_TYPE_FLASH: // �߱½
		RenderSprite->SetTransform(&_matWorld);
		RenderSprite->Draw(pTexInfo->pTexture, NULL,
			_vCenter, _vPosition, D3DCOLOR_ARGB(255, 0, 0, 0));
		break;
	}
}
void CRenderMgr::MultiRender()
{
}