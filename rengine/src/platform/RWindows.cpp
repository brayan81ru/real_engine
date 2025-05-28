#include "RWindows.h"
#include <stdexcept>
namespace REngine {
    RWindows::RWindows(const char* title, int width, int height)
        : m_width(width), m_height(height) {
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            throw std::runtime_error(SDL_GetError());
        }

        m_window = SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            width, height,
            SDL_WINDOW_RESIZABLE | SDL_WINDOW_VULKAN  // Or SDL_WINDOW_METAL/D3D
        );

        if (!m_window) {
            throw std::runtime_error(SDL_GetError());
        }
    }

    RWindows::~RWindows() {
        SDL_DestroyWindow(m_window);
        SDL_Quit();
    }

    bool RWindows::PollEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                m_isRunning = false;
            }
        }
        return m_isRunning;
    }

    void* RWindows::GetNativeHandle() const {
        SDL_SysWMinfo wmInfo;
        SDL_VERSION(&wmInfo.version);
        SDL_GetWindowWMInfo(m_window, &wmInfo);

#if defined(_WIN32)
        return wmInfo.info.win.window;  // HWND (Windows)
#elif defined(__APPLE__)
        return wmInfo.info.cocoa.window; // NSWindow* (macOS)
#else
        return wmInfo.info.x11.window;  // X11 Window (Linux)
#endif
    }
}