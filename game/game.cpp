#define SDL_MAIN_HANDLED
#include <iostream>
#include "../rengine/src/renderer/RRenderer.h"
#include "../rengine/src/platform//RWindows.h"

int main() {
    // Initialize SDL window
    REngine::RWindows window("Real Engine", 1280, 720);

    // Initialize Diligent renderer
    REngine::RRenderer renderer(window);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}