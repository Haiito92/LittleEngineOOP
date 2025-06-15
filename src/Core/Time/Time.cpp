//
// Created by Antoine Hanna on 6/7/2025
//
#include "LittleEngine/Core/Time/Time.h"

#include <chrono>
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

    std::string Time::GetCurrentTimeFormattedString() const {
        auto now = std::chrono::system_clock::now();
        std::time_t t = std::chrono::system_clock::to_time_t(now);
        std::tm local_tm = *std::localtime(&t);

        std::ostringstream oss;
        oss << std::put_time(&local_tm, "%H:%M:%S");
        return oss.str();
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
