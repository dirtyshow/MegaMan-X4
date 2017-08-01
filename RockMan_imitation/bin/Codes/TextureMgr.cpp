#include "stdafx.h"
#include "TextureMgr.h"
#include "Texture.h"
#include "SingleTexture.h"
#include "MultiTexture.h"

#define MESSAGESIZE 128

void CTextureMgr::Release(CTexture * pTexture, TEX_TYPE& type)
{
	// �ش� �ؽ��Ŀ� ���� Release()�� ���ִ� ���� �Լ�(?)
	if (type == TEXTYPE_SINGLE)
	{
		pTexture->Release();
	}
	else
	{
		pTexture->Release();
	}
}

CTextureMgr::CTextureMgr()
{
}
CTextureMgr::~CTextureMgr()
{
	Release();
}

const TEXINFO* CTextureMgr::GetTexture(const TCHAR* pObjKey, const TCHAR* pStateKey, const int& iCnt){
map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.find(pObjKey);
	if (iter == m_MapTexture.end()) return NULL; // Not found
	else return iter->second->GetTexture(pStateKey, iCnt); 

	return nullptr; // Not Success == error
}

HRESULT CTextureMgr::InsertTexture(const TCHAR *pFileName, const TEX_TYPE type,
	const TCHAR *pObjKey, const TCHAR *pStateKey /*=NULL*/, const int &cnt /*=0*/)
{
	/* Object�� �ؽ��İ� �ϳ��� ������ �ٷ� Insert ���� */
	map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.find(pObjKey);
	CTexture* pTexture = nullptr;

	/* Insert new Texture of new Object */
	if (iter == m_MapTexture.end())
	{
		
		
		switch (type) {
		case TEXTYPE_SINGLE:
			pTexture = new CSingleTexture();
			break;
		case TEXTYPE_MULTI:
			pTexture = new CMultiTexture();
			break;
		}

		if (FAILED(pTexture->InsertTexture(pFileName, type, pObjKey, pStateKey, cnt)))
		{
			return E_FAIL;
		}

		m_MapTexture.insert(make_pair(pObjKey, pTexture));
	}
	else
	{
		//if (type == TEXTYPE_SINGLE)
		//{
		//	WCHAR Message[MESSAGESIZE] = L"Continue? Your Texture was overlapped:";
		//	lstrcat(Message, pObjKey);
		//	if (IDOK == MessageBox(g_hWnd, Message, L"Caution", MB_OKCANCEL))
		//	{
		//		CTexture* pTexture = nullptr;
		//		iter->second->Release(); // Direct Delete
		//		pTexture = (iter->second);
		//		if (FAILED(pTexture->InsertTexture(pFileName,, cnt)))
		//		{
		//			return E_FAIL;
		//		}
		//		m_MapTexture.insert(make_pair(pObjKey, pTexture));
		//		return S_OK;
		//	}
		//	// Not Create, Not release established Texture
		//	return S_OK;
		//}
		//else // == TEXTYPE_MULTI
		//{
		//	CMultiTexture* pMultiTexture = (CMultiTexture*)(iter->second);
		//	if (pMultiTexture->CheckOverlapState(pStateKey))
		//	{
		//		WCHAR Message[MESSAGESIZE] = L"Continue? Your Multi_StateKey was overlapped:";
		//		lstrcat(Message, pStateKey);
		//		if (IDOK == MessageBox(g_hWnd, Message, L"Caution", MB_OKCANCEL))
		//		{
		//			if (FAILED(pMultiTexture->Release(pStateKey))) // ��Ƽ Ư�� �κи� Release() �Ѵ�.
		//			{
		//				return E_FAIL;
		//			}
		//			CTexture* pTexture = nullptr;
		//			
		//			if (FAILED(pTexture->InsertTexture(pFileName, pStateKey, cnt)))
		//			{
		//				return E_FAIL;
		//			}
		//			m_MapTexture.insert(make_pair(pObjKey, pTexture));
		//			return S_OK;
		//		}
		//	}
		//	// Not Create
		//	return S_OK;
		//}
		//MessageBox(g_hWnd, L"Already inserted files!", L"Overlapped", MB_OK); 
		switch (type) {
		case TEXTYPE_SINGLE:
			MessageBox(g_hWnd, L"SingleTexture Overlaped fix your codes...", L"Error!", MB_OK);
			return E_FAIL;
			break;
		case TEXTYPE_MULTI:
			// TODO: ��Ƽ�ؽ����� ��쿡�� pStateKey�� ���������� ���� �ߺ�ó�� �ڵ尡 �ٸ���.
			// 1. pStateKey�� �̹� ������ ��� ������ ���� ����
			// 2. pStateKey�� ���� ��� �ٸ� State�� ����� ������ ���� ������ִ� �ڵ带 �־�����.
			if (((iter->second))->GetTexture(pStateKey) == nullptr) {
				// ���� �߰�
				iter->second->InsertTexture(pFileName, pStateKey, cnt);
			}
			else
			{
				// �̹� pStateKey�� ����� ���� �߻� ó��
				return E_FAIL;
			}
			break;
		}
	}
	return S_OK;
}