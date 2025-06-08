//
// Created by Antoine Hanna on 08/06/2025.
//

#ifndef IGAME_H
#define IGAME_H

namespace LittleEngine::Core {

    class IGame {
    public:
        virtual void Init() = 0;
        virtual void Update(float deltaTime) = 0;
        virtual void Render();
        virtual void Shutdown();
        virtual ~IGame();
    };

}

#endif //IGAME_H
