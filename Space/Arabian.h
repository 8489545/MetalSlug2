#pragma once
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

	void Gravity();

	void Update(float deltaTime,float Time);
	void Render();
	void OnCollision(Object* other);
};

