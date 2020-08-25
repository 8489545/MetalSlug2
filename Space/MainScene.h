#pragma once
class MainScene : public Scene
{
	Sprite* m_Player;
	Animation* m_Ani;
public:
	MainScene();
	~MainScene();

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();
};

