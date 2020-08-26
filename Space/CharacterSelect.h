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

	Animation* m_Marco;
	Animation* m_Eri;
	Animation* m_Tarma;
	Animation* m_Fio;
public:
	CharacterSelect();
	~CharacterSelect();

	void Init();
	void Release();

	int m_NowSelectCharacter;
	bool m_PanelUp[4];
	float m_PanelSpeed[4];

	bool m_Decision;

	void PanelUp(int PanelNum);
	void PanelDown(int PanelNum);

	void SetCharacter();

	void DecisionCharacter();

	void Update(float deltaTime, float Time);
	void Render();
};

