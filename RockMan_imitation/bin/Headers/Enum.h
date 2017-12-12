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
	OBJ_NUM_BG, // 맨 뒤에 움직이는 배
	OBJ_NUM_BG2, // 그 앞에 움직이는 작은 배
	OBJ_NUM_BG3, // 고정되어 있는 배
	OBJ_NUM_BG4, // 장식물
	OBJ_NUM_WALL, // 벽
	OBJ_NUM_PLFORM, // 바닥
	OBJ_NUM_MONSTER, // 몹
	OBJ_NUM_PLAYER, // 플레이어
	OBJ_NUM_UI, //  피통바
};

enum SOUND_INDEX
{
	E_SOUND_THEME = 0,
	E_SOUND_READY,
	E_SOUND_LAZER,
	E_SOUND_DASH,
	E_SOUND_JUMP,
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
	E_STATUS_ATTACKED, // 공격받는상태
	E_STATUS_IDLE, // 멈춰있는상태
	E_STATUS_WALK, // 걷는상태
	E_STATUS_DASH, // 대쉬상태
	E_STATUS_DASHEND, // 대쉬끝상태
	E_STATUS_JUMPSTART, // 점프 혹은 공중에서 떨어질 때 상태
	E_STATUS_JUMPOFF, // 점프력이 마이너스가 되기 시작하는 상태
	E_STATUS_JUMPDOWN, // 떨어지기 시작 (발판에서 떨어지거나 공중 점프력이 -가 되기 시작)
	E_STATUS_WALL, // 벽에붙은상태
	E_STATUS_DAMAGED, // 처맞는상태
};

enum POS_STATION // 충돌 검사에서 유용하게 사용됨
{
	E_POS_STATION_GROUND,
	E_POS_STATION_AIR,
	E_POS_ATTACH_WALL,
};