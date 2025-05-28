#define SDL_MAIN_HANDLED
#include <iostream>
#include "../rengine/src/core/RCore.h"

int main() {
    auto engine = new REngine::RCore();
    std::cout << "Hello, World!" << std::endl;
    return 0;
}