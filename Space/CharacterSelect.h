#pragma once
constexpr int Marco = 0;
constexpr int Eri = 1;
constexpr int Tarma = 2;
constexpr int Fio = 3;
constexpr int MaxCharacter = 3;

class CharacterSelect : public Scene
{
	Sprite* m_BG;
	Sprite* m_Panels[4];
	Sprite* m_Title;
	Sprite* m_Player[4];

	Sprite* m_A;
public:
	CharacterSelect();
	~CharacterSelect();

	void Init();
	void Release();

	int m_NowSelectCharacter;

	void Update(float deltaTime, float Time);
	void Render();
};

