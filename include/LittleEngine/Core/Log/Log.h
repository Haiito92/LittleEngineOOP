//
// Created by Antoine Hanna on 08/06/2025
//
#ifndef LOG_H
#define LOG_H
#pragma once
#include <format>
#include <iostream>

namespace LittleEngine::Core {

    class Log {
    public:
        template <typename... Args>
        static void LogInfo(std::format_string<Args...> fmt, Args&&... args) {
            const std::string message = std::format(fmt, std::forward<Args>(args)...);
            LogMessage(message);
        }

        template <typename... Args>
        static void LogWarning(std::format_string<Args...> fmt, Args&&... args) {
            const std::string message = std::format(fmt, std::forward<Args>(args)...);
            LogMessage(message);
        }

        template <typename... Args>
        static void LogError(std::format_string<Args...> fmt, Args&&... args) {
            const std::string message = std::format(fmt, std::forward<Args>(args)...);
            LogMessage(message);
        }

    private:
        static void LogMessage(const std::string& message) {
            std::cout << message << std::endl;
        }
    };
}

#endif //LOG_H
