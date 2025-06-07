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
    }
}
