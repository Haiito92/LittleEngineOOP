//
// Created by Antoine Hanna on 08/06/2025
//
#include "LittleEngine/Core/Log/Log.h"
#pragma once

namespace LittleEngine::Core {
    void Log::SetColor(WORD color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }
}
