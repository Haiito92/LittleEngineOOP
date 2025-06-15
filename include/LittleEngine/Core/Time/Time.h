//
// Created by Antoine Hanna on 6/7/2025
//
#ifndef TIME_H
#define TIME_H
#pragma once
#include <string>
#include <Windows.h>

namespace LittleEngine::Core {

    class Time {
    public:
        static Time& GetInstance();

        void Start();
        void Tick();

        std::string GetCurrentTimeFormattedString() const;
        float GetDeltaTime() const;
        float GetElapsedTime() const;
        float GetFPS() const;

    private:
        Time();
        Time(const Time&) = delete;
        Time(Time&&) = delete;
        ~Time();

        Time& operator=(const Time&) = delete;
        Time& operator=(Time&&) = delete;

        LARGE_INTEGER m_frequency;
        LARGE_INTEGER m_startTimeInTicks;

        float m_currentTime;
        float m_elapsedTime;
        float m_deltaTime;
        float m_FPS;
    };

}

#endif //TIME_H
