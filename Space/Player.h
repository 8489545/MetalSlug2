#pragma once
class Player : public Object
{

public:
	Player(Vec2 Pos);
	~Player();

	void Update(float deltaTime,float Time);
	void Render();
};

