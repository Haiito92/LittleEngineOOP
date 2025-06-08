//
// Created by Antoine Hanna on 6/7/2025
//
#include "LittleEngine/Core/Time/Time.h"

namespace LittleEngine::Core {
    Time & Time::Get() {
        static Time instance;
        return instance;
    }

    void Time::Start() {
        QueryPerformanceFrequency(&m_frequency);
        QueryPerformanceCounter(&m_startTimeInTicks);
    }

    void Time::Tick() {
        LARGE_INTEGER currentTimeInTicks;
        QueryPerformanceCounter(&currentTimeInTicks);
        LONGLONG elapsedTimeInTicks = currentTimeInTicks.QuadPart - m_startTimeInTicks.QuadPart;

        float oldElapsedTime = m_elapsedTime;
        m_elapsedTime = static_cast<float>(elapsedTimeInTicks / m_frequency.QuadPart);
        m_deltaTime = m_elapsedTime - oldElapsedTime;
        m_FPS = 1.0f / m_deltaTime;
    }

    float Time::GetDeltaTime() const{
        return m_deltaTime;
    }

    float Time::GetElapsedTime() const {
        return m_elapsedTime;
    }

    float Time::GetFPS() const {
        return m_FPS;
    }
}
