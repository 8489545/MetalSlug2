#pragma once
class Knife : public Object
{
	Sprite* m_Knife;
public:
	Knife(Vec2 Pos,int Dire,float power,float angle);
	~Knife();

	Vec2 m_StartPos;
	float m_Power;
	float m_Angle;
	float m_Time;
	int m_Dire;

	void Update(float delatTime, float Time);
	void Render();
	void OnCollision(Object* other);
};
