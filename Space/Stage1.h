#pragma once
class Stage1 : public Scene
{
	Sprite* m_Map;
public:
	Stage1() {};
	~Stage1() {};

	void Init();
	void Release();

	void Update(float deltaTime,float Time);
	void Render();
};

