#pragma once
class CharacterSelect : public Scene
{
	Sprite* m_BG;
public:
	CharacterSelect();
	~CharacterSelect();

	void Init();
	void Release();

	void Update(float deltaTime, float Time);
	void Render();
};

