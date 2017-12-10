#pragma once
class CObj;
class CObjSortMgr
{
	// �� �Ŵ����� �������� ������Ʈ�鸸 �����մϴ�.
	DECLARE_SINGLETON(CObjSortMgr)
private:
	list<CObj*>* m_Objvector[20];
public:
	void Initialize();
	D3DXVECTOR3 m_vecScroll;
	HRESULT AddSortedObj(CObj* paramObj);
	void ProgressObjects();
	void RenderObjects();
	void Release();
public:
	CObjSortMgr();
	~CObjSortMgr();
};
