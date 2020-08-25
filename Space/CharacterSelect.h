#pragma once
enum class Character
{
	MACRO,
	ERI,
	TARMA,
	FIO,
	NONE
};
class CharacterSelect : public Scene
{
	Sprite* m_BG;

	Sprite* m_Panels[4];
public:
	CharacterSelect();
	~CharacterSelect();

	void Init();
	void Release();

	Character m_Character;

	void Update(float deltaTime, float Time);
	void Render();
};

