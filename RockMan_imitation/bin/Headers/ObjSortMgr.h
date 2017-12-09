#pragma once
class CObj;
class CObjSortMgr
{
	// �� �Ŵ����� �������� ������Ʈ�鸸 �����մϴ�.
	DECLARE_SINGLETON(CObjSortMgr)
private:
	vector<vector<CObj*>> m_Objvector;
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
