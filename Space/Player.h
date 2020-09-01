#pragma once
class PlayerState;
class Player : public Object
{
	Animation* m_Top;
	Animation* m_Bottom;
	Animation* m_Body;

	Sprite* m_Player;

public:
	Player(Vec2 Pos);
	~Player();

	PlayerState* m_State;
	std::wstring m_Weapon;

	float m_JumpTime;
	float m_JumpPower;
	float m_JumpAccel;
	Vec2 Pos;

	bool m_isGround;
	int m_Dire;
	float m_vY;
	float m_DistanceGround;

	float m_Speed;

	void ChangeImage(std::wstring top,int topfirst,int toplast, std::wstring bottom, int bottomfirst,int bottomlast);
	void ChangeImage(std::wstring body,int first,int last);

	void Update(float deltaTime,float Time);
	void Render();

	void SetImagePos();

	void JumpRun();
	void Move();
	void Jump();
	void Gravity();
};

