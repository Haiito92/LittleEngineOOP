//
// Created by Antoine Hanna on 6/7/2025
//
#ifndef TIME_H
#define TIME_H
#pragma once

namespace LittleEngine::Core {

    class Time {
    public:
        Time();
        Time(const Time&) = delete;
        Time(Time&&) = delete;
        ~Time();

        Time& operator=(const Time&) = delete;
        Time& operator=(Time&&) = delete;
    private:
    };

}

#endif //TIME_H
