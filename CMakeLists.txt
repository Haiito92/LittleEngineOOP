cmake_minimum_required(VERSION 3.20)
project(LittleEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set up engine source files (could glob or list manually)
file(GLOB_RECURSE LITTLE_ENGINE_SRC CONFIGURE_DEPENDS
        src/*.cpp
        include/*.h)

# Build static library for the engine
add_library(LittleEngine STATIC ${LITTLE_ENGINE_SRC})

# Include all engine subdirs
target_include_directories(LittleEngine
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Link system libs (for Win32)
target_link_libraries(LittleEngine PRIVATE
    user32
    gdi32
    d3d12
    dxgi
    dxguid
)
