#	include "stdafx.h"
#include "RenderMgr.h"

//Global Variables
FADE_STATE FadeState = E_FADE_STATE_ToWHITE;
int FadeAlpha = 255;

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



void CRenderMgr::EffectsFade(const TEXINFO *rTexInfo, D3DXMATRIX &_matWorld,
	D3DXVECTOR3 &_vCenter, D3DXVECTOR3 &_vPosition)
{
	if (FadeState == E_FADE_STATE_ToBLACK)  // Fade out Fading in the black
	{
		if (FadeAlpha <= 255) 
			FadeAlpha += 2;
		
		if (FadeAlpha >= 255)
		{
			FadeAlpha = 255;
			// Sit for x number of frames and show the loading screen
			//then fade back in 
			FadeState = E_FADE_STATE_DONE;
		}
		else
		{
			// 0 alpha = clear 255 = opaque
			RenderSprite->SetTransform(&_matWorld);
			RenderSprite->Draw(rTexInfo->pTexture, NULL, &_vCenter,
				&_vPosition, D3DCOLOR_ARGB(FadeAlpha, 0, 0, 0));
		}
	}

	if (FadeState == E_FADE_STATE_ToWHITE) //Fade back in  but fade out the black 
	{
		if (FadeAlpha >= 0) 
			FadeAlpha -= 1;

		if (FadeAlpha <= 0)
		{
			FadeAlpha = 0;
			//We are faded back in 
			//done 
			FadeState = E_FADE_STATE_DONE;
		}
		else
		{
			// 0 alpha = clear 255 = opaque
			RenderSprite->SetTransform(&_matWorld);
			RenderSprite->Draw(rTexInfo->pTexture, NULL, &_vCenter,
				&_vPosition, D3DCOLOR_ARGB(FadeAlpha, 255, 255, 255));
		}
	}
}

void CRenderMgr::SingleRender(const TEXINFO *rTexInfo, D3DXMATRIX& _matWorld,
	D3DXVECTOR3 &_vCenter, D3DXVECTOR3 &_vPosition, SINGLE_RENDER_TYPE type, FRAME _frame)
{
	//_vPosition->x *= _frame;
	//_vPosition->y *= _frame;
	switch (type)
	{
	case E_SINGLE_RENDER_TYPE_STRAIGHT:
		RenderSprite->SetTransform(&_matWorld);
		RenderSprite->Draw(rTexInfo->pTexture, NULL,
			&_vCenter, &_vPosition, D3DCOLOR_ARGB(255, 255, 255, 255));
		break;
	case E_SINGLE_RENDER_TYPE_FLASH: // �߱½
		// �̿ϼ�
		RenderSprite->SetTransform(&_matWorld);
		RenderSprite->Draw(rTexInfo->pTexture, NULL,
			&_vCenter, &_vPosition, D3DCOLOR_ARGB(255, 0, 0, 0));
		break;
	case E_SINGLE_RENDER_TYPE_FADING:
		EffectsFade(rTexInfo, _matWorld, _vCenter, _vPosition);
		break;
	}
}
void CRenderMgr::MultiRender()
{
	
}