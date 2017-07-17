#pragma once
/*

// Sprite Texture Mode Manager //
// Encoding with UTF-Korean
 �̱��ؽ��Ĵ� Object�� 1��1 �ؽ��� ������ ����μ�
������Ʈ�� �ϳ� �ִٸ� �� ������Ʈ�� ���� �ؽ��Ĵ� �� �ϳ��� �ε�ȴ�.
����, �ε��� ��ä�� �ҷ��ͼ� Sprite�� ��ǥ���������� 0~32���� ������,
32~64 ������... �̷������� �ҷ��ͼ� ������. 
�������ڸ� �� �̹��� ���Ͽ� ���ؼ� ũ�⺰ ������ �Ͽ� ��������Ʈ�ϴ� ����̴�.

 ��Ƽ�ؽ��Ĵ� Object�� 1��n �ؽ��� ������ ����μ�
������Ʈ�� �ϳ� �ִٸ� �� ������Ʈ�� ���� ��Ʈ�� �����ų� �ٸ� �ΰ���Ҹ� �߰��Ͽ� 
���� ���� ���Ϸ� ������ ����̴�. ���� ��, ���� ��������Ʈ�Ѵٰ� ġ�� ��01, ��02 ...
�̷� ������ �� ������ ���� ������ ������ ����.
�߸� �����ϸ� ��Ƽ �ؽ��Ŀ��� �̱� �ؽ��� ����� ����ؼ� ��� ���� �ִµ� �̰��� ����ϱⰡ �����.
�׷��� �� ���Ϻ��� ������ �� ��ü�� �״�� ������ ��Ű�°� �ٶ����ϴٰ� �ϰڴ�.
*/
class CTexture;
class CTextureMgr
{
	DECLARE_SINGLETON(CTextureMgr)
private:
	// Memory Buckets for Textures. Your texture will be saved in m_MapTexture.
	map<const TCHAR*, CTexture*> m_MapTexture;

	// Stock file names in Stack
	std::stack<const TCHAR*> m_stFileName;
public:
	const TEXINFO* GetTexture(const TCHAR* pObjKey,
		const TCHAR* pStateKey = NULL, const int& iCnt = 0);
	HRESULT InsertTexture(const TCHAR* pFileName, const TEX_TYPE type, const TCHAR* pObjKey, const TCHAR* pStateKey = NULL, const int& cnt = 0);
	size_t Show_FileCounts() {
		return m_stFileName.size(); // Show how many textures are inserted in m_MapTexture.
	}
	virtual void Release() final { // ��ü �������� �ؽ��� ������ ������Ų��.
		for (map<const TCHAR*, CTexture*>::iterator iter = m_MapTexture.begin();
			iter != m_MapTexture.end(); /*Continue*/) {
			delete iter->second;
			iter->second = NULL;
			++iter;
		}
		m_MapTexture.clear();
	}
	void Release(CTexture *pTexture, TEX_TYPE& type);
private:
	CTextureMgr();
public:
	~CTextureMgr();
};

