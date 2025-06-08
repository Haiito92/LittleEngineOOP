//
// Created by Antoine Hanna on 08/06/2025.
//

#include "LittleEngine/Core/App/App.h"

#include "LittleEngine/Core/Log/Log.h"
#include "LittleEngine/Window/Window.h"


namespace LittleEngine::Core {

    using Window::Window;

    void App::Init(IGame *game) {
        m_game = game;
        m_game->Init();
    }

    void App::Run(HINSTANCE hInstance) {
        Window appWindow = Window(hInstance, 800, 600, L"App");

        Time& time = Time::GetInstance();
        time.Start();

        while (appWindow.ProcessMessages()) {
            //App or Game loop
            time.Tick();
            m_game->Update(time.GetDeltaTime());
        }
    }

    void App::Shutdown() {
        m_game->Shutdown();
    }

    App::App() {

    }

    App::~App() {

    }
}
