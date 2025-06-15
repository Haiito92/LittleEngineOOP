//
// Created by Antoine Hanna on 08/06/2025
//
#include "LittleEngine/Core/Log/Log.h"
#pragma once

namespace LittleEngine::Core {
    std::string Log::HRESULTToString(HRESULT hr) {
        LPSTR messageBuffer = nullptr;

        // FormatMessage allocates a buffer and fills it with the error message string
        DWORD size = FormatMessageA(
            FORMAT_MESSAGE_ALLOCATE_BUFFER | // Let the function allocate memory for the message buffer
            FORMAT_MESSAGE_FROM_SYSTEM |     // Get message from system error messages
            FORMAT_MESSAGE_IGNORE_INSERTS,   // Ignore inserts like %1, %2
            nullptr,                        // No source, since we want system message
            hr,                             // The HRESULT code
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), // Language to use
            (LPSTR)&messageBuffer,          // Output buffer pointer (cast to LPSTR*)
            0,                              // Minimum size for output buffer
            nullptr                         // Arguments for inserts, ignored here
        );

        std::string message;

        if (size == 0)
        {
            // If FormatMessage fails, fallback with unknown error message
            message = "Unknown message code: " + std::to_string(hr);
        }
        else
        {
            message = std::string(messageBuffer, size);

            // Remove trailing newlines/carriage returns (FormatMessage often adds those)
            while (!message.empty() && (message.back() == '\n' || message.back() == '\r'))
                message.pop_back();

            // Free the buffer allocated by FormatMessage
            LocalFree(messageBuffer);
        }

        return message;
    }

    void Log::SetColor(WORD color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }
}
