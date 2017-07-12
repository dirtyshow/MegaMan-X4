#pragma once
#include "Include.h"
/* UTF-Korean */
/*
Rendering Helper for each Sprite Mode; Single, Multi
��������Ʈ ��忡 ���� �������� �����ִ� �Ŵ���
�̱��϶�, ���� ��Ÿ�� ��ǥ�� �����ؼ� �����Ӻ��� �����̰� ���̰� �� �� �ִ�.
��Ƽ�϶�, �ൿ�� ���� �� ���� ������ŭ �����Ͽ� �����Ӻ��� �����̰� ���̰� �� �� �ִ�.
*/
class CRenderMgr
{
	DECLARE_SINGLETON(CRenderMgr)
public:
	void SingleRender(); // Option �ʿ���, �Ϲ������� ����(��ü) �ɼǿ� ���� ����
	void MultiRender();
private:
	CRenderMgr();
public:
	~CRenderMgr();
};

