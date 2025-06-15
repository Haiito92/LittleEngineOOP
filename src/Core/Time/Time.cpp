//
// Created by Antoine Hanna on 6/7/2025
//
#include "LittleEngine/Core/Time/Time.h"

#include <iostream>
#include <bits/ostream.tcc>

namespace LittleEngine::Core {
    Time & Time::GetInstance() {
        static Time instance;
        return instance;
    }

    void Time::Start() {
        QueryPerformanceFrequency(&m_frequency);
        QueryPerformanceCounter(&m_startTimeInTicks);

        m_currentTime = static_cast<float>(m_startTimeInTicks.QuadPart / m_frequency.QuadPart);
    }

    void Time::Tick() {
        LARGE_INTEGER currentTimeInTicks;
        QueryPerformanceCounter(&currentTimeInTicks);

        m_currentTime = static_cast<float>(currentTimeInTicks.QuadPart / m_frequency.QuadPart);

        LONGLONG elapsedTimeInTicks = currentTimeInTicks.QuadPart - m_startTimeInTicks.QuadPart;

        float oldElapsedTime = m_elapsedTime;
        m_elapsedTime = static_cast<float>(elapsedTimeInTicks / m_frequency.QuadPart);
        m_deltaTime = m_elapsedTime - oldElapsedTime;
        m_FPS = 1.0f / m_deltaTime;
    }

    std::string Time::GetCurrentTimeFormattedString() const {
        std::cout << "Current total seconds: " << m_currentTime << std::endl;
        int hours = m_currentTime / 60.0f / 60.0f;
        std::cout << "Current hours: " << hours << std::endl;
        int minutes = (m_currentTime - (hours * 60.0f * 60.0f)) / 60.0f;
        std::cout << "Current minutes: " << minutes << std::endl;
        int seconds = m_currentTime - (minutes * 60.0f);
        std::cout << "Current seconds: " << seconds << std::endl;

        return std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(seconds);
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

    Time::Time()
    : m_frequency{0}, m_startTimeInTicks{0}, m_elapsedTime(0.0f), m_deltaTime(0.0f), m_FPS(0.0f) {
    }

    Time::~Time() = default;
}
