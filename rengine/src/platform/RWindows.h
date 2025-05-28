#pragma once
#include <SDL.h>
#include <memory>
namespace REngine {
    class RWindows {
    public:
        RWindows(const char* title, int width, int height);
        ~RWindows();

        bool PollEvents();  // Returns false if user requests quit
        void* GetNativeHandle() const;

        // Getters
        int GetWidth() const { return m_width; }
        int GetHeight() const { return m_height; }

    private:
        SDL_Window* m_window = nullptr;
        int m_width, m_height;
        bool m_isRunning = true;
    };
}