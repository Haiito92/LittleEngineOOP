//
// Created by Antoine Hanna on 6/15/2025
//
#pragma once
#include "LittleEngine/Rendering/Device.h"
#include <wrl.h>
#include <dxgi1_6.h>

#include "LittleEngine/Core/Log/Log.h"

using Microsoft::WRL::ComPtr;
using LittleEngine::Core::Log;

namespace LittleEngine::Rendering {

    bool Device::Init() {
        HRESULT factoryCreationHr;

        ComPtr<IDXGIFactory6> factory;
        factoryCreationHr = CreateDXGIFactory1(IID_PPV_ARGS(&factory));

        if (FAILED(factoryCreationHr)) {
            Log::LogError("Render Device", "Factory creation failed: " + Log::HRESULTToString(factoryCreationHr));
            return false;
        }else {
            Log::LogInfo("Render Device", "Factory creation succeeded: " + Log::HRESULTToString(factoryCreationHr));
        }

        //ComPtr<IDXGIAdapter4> adapter;
        //factory->EnumAdapterByGpuPreference(0, DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE, IID_PPV_ARGS(&adapter));
        return true;
    }
}
