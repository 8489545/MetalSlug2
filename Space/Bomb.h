#pragma once
class Bomb : public Object
{
	Sprite* m_BombBox;
	Animation* m_Bomb;

public:
	Bomb(Vec2 Pos,int Dire);
	~Bomb();

	int m_Time;
	float m_GR;
	float m_Power;
	Vec2 m_Pos;
	int m_Dire;


	void Update(float deltaTime,float Time);
	void Render();
	void OnCollision(Object* other);
};

