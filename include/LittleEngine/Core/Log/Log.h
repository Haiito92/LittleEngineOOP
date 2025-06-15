//
// Created by Antoine Hanna on 08/06/2025
//
#ifndef LOG_H
#define LOG_H
#pragma once
#include <format>
#include <iostream>

#include "LittleEngine/Core/App/App.h"

namespace LittleEngine::Core {

    class Log {
    public:
        template <typename... Args>
        static void LogInfo(const std::string& tag, std::format_string<Args...> fmt, Args&&... args) {
            SetColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            LogMessage(tag, fmt, std::forward<Args>(args)...);
        }

        template <typename... Args>
        static void LogWarning(const std::string& tag, std::format_string<Args...> fmt, Args&&... args) {
            SetColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            LogMessage(tag, fmt, std::forward<Args>(args)...);
            SetColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }

        template <typename... Args>
        static void LogError(const std::string& tag, std::format_string<Args...> fmt, Args&&... args) {
            SetColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
            LogMessage(tag, fmt, std::forward<Args>(args)...);
            SetColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        }

    private:
        template <typename... Args>
        static void LogMessage(const std::string& tag, std::format_string<Args...> fmt, Args&&... args) {
            const std::string message = std::format(fmt, std::forward<Args>(args)...);
            std::cout << "[" + Time::GetInstance().GetCurrentTimeFormattedString() + "][" + tag + "]: " + message << std::endl;
        }

        static void SetColor(WORD color);
    };
}

#endif //LOG_H
