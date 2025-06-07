//
// Created by Antoine Hanna on 6/7/2025
//
#ifndef WINDOW_H
#define WINDOW_H
#pragma once
#include <Windows.h>
#include <string>

namespace LittleEngine::Window {

    class Window {
    public:
        Window(HINSTANCE hinstance, int width, int height, const std::wstring& title);
        Window(const Window&) = delete;
        Window(Window&&) = delete;
        ~Window();

        Window& operator=(const Window&) = delete;
        Window& operator=(Window&&) = delete;

        HWND GetHandle() const;
        bool ProcessMessages();

    private:
        HWND m_hWnd;
        int m_width;
        int m_height;
        std::wstring m_title;

        static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    };

}

#endif //WINDOW_H
