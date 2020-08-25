#pragma once
enum class State
{
	IDLE,
	RUN,
	NONE
};
class Player : public Object
{
	Animation* m_PlayerTop;
	Animation* m_PlayerBottom;
public:
	Player(Vec2 Pos);
	~Player();

	std::wstring Dire;
	State m_State;

	int m_PlayerDirection;

	bool m_isChangedPlayerState;
	void SetPlayerAni();

	void Update(float deltaTime,float Time);
	void Render();
};

