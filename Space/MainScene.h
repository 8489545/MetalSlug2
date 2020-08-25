#pragma once
class MainScene : public Scene
{
	Sprite* m_Logo;
	Sprite* m_Neogeo;

	Animation* m_Start;
	Animation* m_Edit;
	Animation* m_Exit;

	LineMgr* m_StartLine;

public:
	MainScene();
	~MainScene();

	bool m_DestroyNeogeo;

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();
};
