#pragma once
class CObj;
class CObjSortMgr
{
	// �� �Ŵ����� �������� ������Ʈ�鸸 �����մϴ�.
	DECLARE_SINGLETON(CObjSortMgr)
private:
	vector<list<CObj*>> m_ObjList;
public:
	HRESULT AddSortedObj(CObj* paramObj);
	void RenderObjects();
	void Release();
public:
	CObjSortMgr();
	~CObjSortMgr();
};

