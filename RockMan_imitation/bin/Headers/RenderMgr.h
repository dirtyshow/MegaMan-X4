#pragma once
#include "Include.h"
#include "Device.h"
/* UTF-Korean */
/*
Rendering Helper for each Sprite Mode; Single, Multi
스프라이트 모드에 따른 랜더링을 도와주는 매니져
싱글일땐, 랜더 스타팅 좌표를 조정해서 프레임별로 움직이게 보이게 할 수 있다.
멀티일땐, 행동에 따른 각 파일 갯수만큼 랜더하여 프레임별로 움직이게 보이게 할 수 있다.
*/
class CRenderMgr
{
	DECLARE_SINGLETON(CRenderMgr)
private:
	const LPD3DXSPRITE& RenderSprite = GET_SINGLE(CDevice)->GetSprite();
public:
	void SingleRender(const TEXINFO*& pTexInfo, D3DXMATRIX& _matWorld,
		D3DXVECTOR3*& _vCenter, 
		D3DXVECTOR3*& _vPosition, SINGLE_RENDER_TYPE type, FRAME& _frame); // Option 필요함, 일반적으로 렌더(전체) 옵션에 따른 랜더
	void MultiRender();
private:
	CRenderMgr();
public:
	~CRenderMgr();
};