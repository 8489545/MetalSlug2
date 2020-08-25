#pragma once
class MainScene : public Scene
{
	Sprite* m_Logo;
	Sprite* m_Neogeo;

	Animation* m_Start;
	Animation* m_Edit;
	Animation* m_Exit;

public:
	MainScene();
	~MainScene();

	bool m_DestroyNeogeo;

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();
};
