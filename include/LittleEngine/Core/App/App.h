//
// Created by Antoine Hanna on 08/06/2025.
//

#ifndef APP_H
#define APP_H
#include "LittleEngine/Core/Game/IGame.h"
#include "LittleEngine/Core/Time/Time.h"

namespace LittleEngine::Core {

    class App {
    public:
        App();
        App(const App&) = delete;
        App(App&&) = delete;
        ~App();

        App& operator=(const App&) = delete;
        App& operator=(App&&) = delete;

        void Init(IGame* game);
        void Run(HINSTANCE hInstance);
        void Shutdown();
    private:
        IGame* m_game;
    };

}

#endif //APP_H
