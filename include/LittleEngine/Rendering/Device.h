//
// Created by Antoine Hanna on 6/15/2025
//
#ifndef DEVICE_H
#define DEVICE_H
#pragma once

namespace LittleEngine::Rendering {

    class Device {
    public:
        Device();
        Device(const Device&) = delete;
        Device(Device&&) = delete;
        ~Device();
    
        Device& operator=(const Device&) = delete;
        Device& operator=(Device&&) = delete;

        bool Init();
    private:
    };

}

#endif //DEVICE_H
