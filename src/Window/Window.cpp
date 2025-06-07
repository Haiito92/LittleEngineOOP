//
// Created by Antoine Hanna on 6/7/2025
//
#include "LittleEngine/Window/Window.h"

namespace LittleEngine::Window {
    Window::Window(HINSTANCE hinstance, int width, int height, const std::wstring &title)
        :m_width(width), m_height(height), m_title(title) {

        WNDCLASS wc = {};
        wc.lpfnWndProc = WndProc;
        wc.hInstance = hinstance;
        wc.lpszClassName = reinterpret_cast<LPCSTR>(L"WindowClass");

        RegisterClass(&wc);

        RECT rect = {0, 0, m_width, m_height};
        AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

        m_hWnd = CreateWindowEx(
            0,
            wc.lpszClassName,
            reinterpret_cast<LPCSTR>(m_title.c_str()),
            WS_OVERLAPPEDWINDOW,
            CW_USEDEFAULT,
            CW_USEDEFAULT,
            rect.right - rect.left,
            rect.bottom - rect.top,
            nullptr,
            nullptr,
            hinstance,
            nullptr
            );

        ShowWindow(m_hWnd, SW_SHOW);
    }

    Window::~Window() {
        DestroyWindow(m_hWnd);
    }

    HWND Window::GetHandle() const {
        return m_hWnd;
    }

    bool Window::ProcessMessages() {
        MSG msg = {};
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) return false;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        return true;
    }

    LRESULT Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

        switch (message) {
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
        }

        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}
