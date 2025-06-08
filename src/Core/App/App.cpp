//
// Created by Antoine Hanna on 08/06/2025.
//

#include "LittleEngine/Core/App/App.h"
#include "LittleEngine/Window/Window.h"


namespace LittleEngine::Core {

    using Window::Window;

    App & App::GetInstance() {
        static App instance;
        return instance;
    }

    void App::Init() {

    }

    void App::Run(HINSTANCE hInstance) {
        Window appWindow = Window(hInstance, 800, 600, L"App");

        Time& time = Time::GetInstance();
        time.Start();

        while (appWindow.ProcessMessages()) {
            //App or Game loop
            time.Tick();

        }
    }

    void App::Shutdown() {

    }

    App::App() {

    }

    App::~App() {

    }
}
