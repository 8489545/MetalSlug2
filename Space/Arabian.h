#pragma once
class ArabianState;
class Arabian : public Object
{
public:
	Sprite* m_Arabian;
	Animation* m_Body;
	Sprite* m_Sight;

	Arabian(Vec2 Pos);
	~Arabian();

	bool m_isGround;
	float m_vY;

	float m_Speed;

	int m_Dire;

	ArabianState* m_State;

	void ChangeImage(std::wstring body, int first, int last);

	void Gravity();
	void SetImagePos();
	void Move(int Dire);

	void Update(float deltaTime,float Time);
	void Render();
	void OnCollision(Object* other);
};

