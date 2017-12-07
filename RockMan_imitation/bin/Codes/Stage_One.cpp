#pragma once
#include "stdafx.h"
#include "Stage_One.h"
#include "TextureMgr.h"
#include "RenderMgr.h"
#include "ObjSortMgr.h"
#include "Factory.h"

#include "BigShip.h"
#include "SmallShip.h"

CStage_One::CStage_One()
{
}
CStage_One::~CStage_One()
{
	Release();
}

HRESULT CStage_One::Initialize(void) {
	// BackGround Initialize
	this->pTextureMgr = GET_SINGLE(CTextureMgr);

	// BG1
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/BackGrounds/Logo.png", TEXTYPE_SINGLE, L"BG", NULL, 0)))
	{
		return E_FAIL;
	}
	// BG2
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/BackGrounds/BG2.png", TEXTYPE_SINGLE, L"BG2", NULL, 0)))
	{
		return E_FAIL;
	}
	// Big Ship
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/BackGrounds/BGOb1.png", TEXTYPE_SINGLE, L"BigShip", NULL, NULL)))
	{
		return E_FAIL;
	}
	// Small Ship
	if (FAILED(pTextureMgr->
		InsertTexture(L"../Resource/BackGrounds/BGOb2.png", TEXTYPE_SINGLE, L"SmallShip", NULL, NULL)))
	{
		return E_FAIL;
	}

	this->pBGTexture = GET_SINGLE(CTextureMgr)->GetTexture(L"BG");
	
	GET_SINGLE(CObjSortMgr)->AddSortedObj( CFactory<CBigShip>::CreateInstance() );
	GET_SINGLE(CObjSortMgr)->AddSortedObj( CFactory<CSmallShip>::CreateInstance() );


	// For BackGrounds
	D3DXMATRIX matScale[2];
	D3DXMATRIX matTrans[2];
	D3DXMatrixTranslation(&matTrans[0], 0, 0, 0);
	D3DXMatrixTranslation(&matTrans[1], 0, 0, 0);
	D3DXMatrixScaling(&matScale[0], 1.0f, 1.0f, 1.f);
	D3DXMatrixScaling(&matScale[1], 1.0f, 1.0f, 1.f);

	BackMatrix[0] = matScale[0] * matTrans[0];
	BackMatrix[1] = matScale[1] * matTrans[1];

	return S_OK;
}
HRESULT CStage_One::Progress(void) { 
	GET_SINGLE(CObjSortMgr)->ProgressObjects();
	return S_OK;
}
HRESULT CStage_One::Render(void) { 
	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"BG", NULL, NULL), this->BackMatrix[0], 
		(D3DXVECTOR3(0, 0, 0)), (D3DXVECTOR3(0,0,0)), E_SINGLE_RENDER_TYPE_STRAIGHT, 0); // ���
	GET_SINGLE(CRenderMgr)->SingleRender(GET_SINGLE(CTextureMgr)->GetTexture(L"BG2", NULL, NULL), this->BackMatrix[1],
		(D3DXVECTOR3(0, 0, 0)), (D3DXVECTOR3(0, 0, 0)), E_SINGLE_RENDER_TYPE_STRAIGHT, 0); // ���2
	return S_OK;

	GET_SINGLE(CObjSortMgr)->RenderObjects();

	return S_OK;
}
HRESULT CStage_One::Release(void) { return S_OK; }