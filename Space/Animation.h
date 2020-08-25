#pragma once
class Animation : public Object
{
private:
	Sprite* m_Anim;

	float m_Delay;
	bool m_AutoPlay;
	float m_FrameCount;

	int m_FirstFrame;
	int m_LastFrame;

public:
	int m_CurrentFrame;
	int A, R, G, B;

public:
	Animation();
	~Animation();

	void AddContinueFrame(std::wstring fileName, int firstFrame, int lastFrame);

	void Init(float delay, bool play);
	void Update(float deltaTime, float time);
	void Render();
};

