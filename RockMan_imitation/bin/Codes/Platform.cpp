#include "stdafx.h"
#include "Platform.h"
#include "TextureMgr.h"
#include "RenderMgr.h"

CPlatform::CPlatform()
{
}


CPlatform::~CPlatform()
{
}

HRESULT CPlatform::Initialize()
{
	// 2�� �̻� ���� �� ����. // 192 * 48
	this->SetSortID(OBJ_NUM_PLFORM);

	D3DXMatrixScaling(&plat[0].matScale, 2, 1.7f, 1);
	D3DXMatrixTranslation(&plat[0].matTrans, 0, 510, 0);
	plat[0].matWorld = plat[0].matScale * plat[0].matTrans;

	plat[0].vCenter = D3DXVECTOR3(0, 0, 0);
	plat[0].vPos = D3DXVECTOR3(0, 0, 0);

	D3DXMatrixScaling(&plat[1].matScale, 2, 1.7f, 1);
	D3DXMatrixTranslation(&plat[1].matTrans, 0, -48, 0);
	plat[1].matWorld = plat[1].matScale * plat[1].matTrans;

	plat[1].vCenter = D3DXVECTOR3(0, 0, 0);
	plat[1].vPos = D3DXVECTOR3(0, 0, 0);

	// ���� ����
	D3DXMatrixScaling(&plat[2].matScale, 2, 1.7f, 1);
	D3DXMatrixTranslation(&plat[2].matTrans, -100, 250, 0);
	plat[2].matWorld = plat[2].matScale * plat[2].matTrans;

	plat[2].vCenter = D3DXVECTOR3(0, 0, 0);
	plat[2].vPos = D3DXVECTOR3(0, 0, 0);

	D3DXMatrixScaling(&plat[3].matScale, 2, 1.7f, 1);
	D3DXMatrixTranslation(&plat[3].matTrans, 1500, 250, 0);
	plat[3].matWorld = plat[3].matScale * plat[3].matTrans;

	plat[3].vCenter = D3DXVECTOR3(0, 0, 0);
	plat[3].vPos = D3DXVECTOR3(0, 0, 0);
	
	return S_OK;
}

HRESULT CPlatform::Progress()
{
	return S_OK;
}

HRESULT CPlatform::Render()
{
	for (int i = 0; i < 4; i++)
	{
		if (i <= 1) 
		{
			GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Platform_long"),
				plat[i].matWorld, plat[i].vCenter, plat[i].vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 0);
		}
		else
		{
			GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"Platform"),
				plat[i].matWorld, plat[i].vCenter, plat[i].vPos, E_SINGLE_RENDER_TYPE_STRAIGHT, 0);
		}
	}	
	return S_OK;
}
