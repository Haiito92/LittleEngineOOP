//
// Created by Antoine Hanna on 08/06/2025.
//

#ifndef APP_H
#define APP_H
#include <memory>
#include <wrl/client.h>

#include "LittleEngine/Core/Game/IGame.h"
#include "LittleEngine/Core/Time/Time.h"
#include "LittleEngine/Window/Window.h"

namespace LittleEngine::Core {

    class App {
    public:
        App();
        App(const App&) = delete;
        App(App&&) = delete;
        ~App();

        App& operator=(const App&) = delete;
        App& operator=(App&&) = delete;

        void Init(HINSTANCE hInstance, IGame* game);
        void Run();
        void Shutdown();
    private:
        void InitializeRenderingModule();

        std::unique_ptr<Window::Window> appWindow;

        IGame* m_game;
    };

}

#endif //APP_H
