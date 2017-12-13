#pragma once
enum DIRECTION
{
	D_LEFT = 0,
	D_RIGHT,
	D_UP,
	D_DOWN,
};

enum FIELD
{
	STAGE_LOGO = 0,
	STAGE_ONE = 1,
	STAGE_TWO = 2,
};

enum OBJ_NUM
{
	OBJ_NUM_BG, // �� �ڿ� �����̴� ��
	OBJ_NUM_BG2, // �� �տ� �����̴� ���� ��
	OBJ_NUM_BG3, // �����Ǿ� �ִ� ��
	OBJ_NUM_BG4, // ��Ĺ�
	OBJ_NUM_WALL, // ��
	OBJ_NUM_PLFORM, // �ٴ�
	OBJ_NUM_MONSTER, // ��
	OBJ_NUM_PLAYER, // �÷��̾�
	OBJ_NUM_UI, //  �����
};

enum SOUND_INDEX
{
	E_SOUND_THEME = 0,
	E_SOUND_READY,
	E_SOUND_LAZER,
	E_SOUND_DASH,
	E_SOUND_JUMP,
	E_SOUND_PLAT,
	E_SOUND_A1,
	E_SOUND_A2,
	E_SOUND_A3,
	E_SOUND_SWORD,
	E_SOUND_BOMB,
	E_SOUND_FIRE,
	E_SOUND_DAMAGED,
	E_SOUND_DESTROY,
};

enum TEX_TYPE
{
	TEXTYPE_SINGLE = 0,
	TEXTYPE_MULTI = 1,
};

enum SINGLE_RENDER_TYPE
{
	E_SINGLE_RENDER_TYPE_STRAIGHT,	// Render full image
	E_SINGLE_RENDER_TYPE_FLASH,		// Render flash
	E_SINGLE_RENDER_TYPE_FADING,	// Render fading
};

enum MULTI_RENDER_TYPE
{
	E_MULTI_RENDER_TYPE_STRAIGHT,	// Render full image
	E_MULTI_RENDER_TYPE_FLASH,		// Render flash
	E_MULTI_RENDER_TYPE_FADING,		// Render fading
};

enum FADE_STATE
{
	E_FADE_STATE_IN = 1,
	E_FADE_STATE_OUT= 2,
	E_FADE_STATE_DONE = 3,
};

enum LOGO_OBJ
{
	LOGO_BACKGROUND,
	LOGO_ROCK_1,
	LOGO_ROCK_2,
	LOGO_ZERO_3,
	LOGO_ZERO_4,
	LOGO_ROCKTEXT_5,
	LOGO_ZEROTEXT_6,
};

enum STATUS
{
	E_STATUS_ATTACKED, // ���ݹ޴»���
	E_STATUS_IDLE, // �����ִ»���
	E_STATUS_WALK, // �ȴ»���
	E_STATUS_DASH, // �뽬����
	E_STATUS_DASHEND, // �뽬������
	E_STATUS_JUMPSTART, // ���� Ȥ�� ���߿��� ������ �� ����
	E_STATUS_JUMPOFF, // �������� ���̳ʽ��� �Ǳ� �����ϴ� ����
	E_STATUS_JUMPDOWN, // �������� ���� (���ǿ��� �������ų� ���� �������� -�� �Ǳ� ����)
	E_STATUS_WALL, // ������������
	E_STATUS_DAMAGED, // ó�´»���
	E_STATUS_A1,
	E_STATUS_A2,
	E_STATUS_A3,
	E_STATUS_FIREATTACK,
	E_STATUS_JUMPATTACK,
};

enum POS_STATION // �浹 �˻翡�� �����ϰ� ����
{
	E_POS_STATION_GROUND,
	E_POS_STATION_AIR,
	E_POS_ATTACH_WALL,
};