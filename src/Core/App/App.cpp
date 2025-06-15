//
// Created by Antoine Hanna on 08/06/2025.
//

#include "LittleEngine/Core/App/App.h"

#include "LittleEngine/Core/Log/Log.h"
#include "LittleEngine/Rendering/Device.h"
#include "LittleEngine/Window/Window.h"


namespace LittleEngine::Core {

    using Window::Window;

    void App::Init(HINSTANCE hInstance, IGame *game) {
        appWindow = std::make_unique<Window>(hInstance, 800, 600, L"App");

        Rendering::Device device = Rendering::Device();
        device.Init();

        m_game = game;
        m_game->Init();
    }

    void App::Run() {
        Time& time = Time::GetInstance();
        time.Start();

        Log::LogInfo("App", "Start running.");

        while (appWindow->ProcessMessages()) {
            //App or Game loop
            time.Tick();
            m_game->Update(time.GetDeltaTime());
        }
    }

    void App::Shutdown() {
        m_game->Shutdown();
    }

    void App::InitializeRenderingModule() {

    }

    App::App() {

    }

    App::~App() {

    }
}
