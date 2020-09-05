#pragma once
class Bullet : public Object
{
	Sprite* m_Bullet;

public:
	Bullet(std::wstring filename,Vec2 arrival,Vec2 pos, float speed);
	~Bullet();

	Vec2 m_Arrival;
	float m_Speed;

	Vec2 Dire;
	float m_Timer;

	void Update(float deltaTime, float Time);
	void Render();
};

