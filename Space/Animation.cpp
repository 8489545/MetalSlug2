#include "stdafx.h"
#include "Animation.h"

Animation::Animation()
	: m_AutoPlay(0)
	, m_CurrentFrame(1)
	, m_Delay(0.f)
	, m_FrameCount(0.f)
	, m_FirstFrame(1)
	, m_LastFrame(1)
	, A(255)
	, R(255)
	, G(255)
	, B(255)
{
}

Animation::~Animation()
{
}

void Animation::AddContinueFrame(std::wstring fileName, int firstFrame, int lastFrame)
{
	m_Anim = Sprite::Create(fileName.c_str());
	m_Anim->SetParent(this);

	m_FirstFrame = firstFrame;
	m_LastFrame = lastFrame;
}

void Animation::Init(float delay, bool play)
{
	m_Delay = delay;
	m_AutoPlay = play;
}

void Animation::Update(float deltaTime, float time)
{
	m_FrameCount += dt;

	if (m_Destroy)
	{
		SetDestroy(true);
	}

	if (m_AutoPlay == true)
	{
		if (m_FrameCount > m_Delay)
		{
			m_CurrentFrame++;
			m_FrameCount = 0.f;
		}
	}
	if (m_CurrentFrame > m_LastFrame)
	{
		m_CurrentFrame = 1;
	}
	m_Anim->Update(deltaTime, time);
}

void Animation::Render()
{
	if (m_Parent)
	{
		SetRect(&m_Parent->m_Collision, m_Parent->m_Position.x - m_Size.x / 2, m_Parent->m_Position.y - m_Size.y / 2,
			m_Parent->m_Position.x + m_Size.x / 2, m_Parent->m_Position.y + m_Size.y / 2);

		m_Parent->m_Size = m_Size;
	}
	else
	{
		SetRect(&m_Collision, m_Position.x - m_Size.x / 2, m_Position.y - m_Size.y / 2,
			m_Position.x + m_Size.x / 2, m_Position.y + m_Size.y / 2);
	}


	SetRect(&m_Anim->m_Rect, static_cast<int>(m_Size.x / m_LastFrame)* (m_CurrentFrame - 1), 0,
		static_cast<int>(m_Size.x / m_LastFrame)* m_CurrentFrame, static_cast<int>(m_Size.y));

	m_Anim->Render();
}