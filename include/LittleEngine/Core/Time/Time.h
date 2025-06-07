//
// Created by Antoine Hanna on 6/7/2025
//
#ifndef TIME_H
#define TIME_H
#pragma once
#include <Windows.h>

namespace LittleEngine::Core {

    class Time {
    public:
        static Time& Get();

        void Start();
        void Tick();

        float GetDeltaTime();
        float GetElapsedTime();
        float GetFPS();

    private:
        Time();
        Time(const Time&) = delete;
        Time(Time&&) = delete;
        ~Time();

        Time& operator=(const Time&) = delete;
        Time& operator=(Time&&) = delete;

        LARGE_INTEGER m_frequency;
    };

}

#endif //TIME_H
