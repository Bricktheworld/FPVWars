#include "window.h"
#include <SDL2/SDL.h>
#include <glad/glad.h>

namespace Platform
{
    struct Window
    {
        SDL_Window *sdl_window   = nullptr;
        SDL_GLContext gl_context = nullptr;
        SDL_Event event_buffer;

        Window()  = default;
        ~Window() = default;

        Window &operator=(const Window &other) = delete;
        Window(const Window &other)            = delete;
    };

    Window *init_window(const char *window_name)
    {
        auto *window = new Window();
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            fprintf(stderr, "Could not initialize sdl2: %s\n", SDL_GetError());
            return nullptr;
        }

        SDL_GL_LoadLibrary(nullptr);

        // Request an OpenGL 4.5 context (should be core)
        SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 5);

        // Also request a depth buffer
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

        SDL_DisplayMode display_info;
        SDL_GetCurrentDisplayMode(0, &display_info);

        window->sdl_window = SDL_CreateWindow(window_name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, display_info.w, display_info.h, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
        if (window == NULL)
        {
            fprintf(stderr, "Could not create window: %s\n", SDL_GetError());
            return nullptr;
        }

        window->gl_context = SDL_GL_CreateContext(window->sdl_window);

        if (window->gl_context == nullptr)
        {
            fprintf(stderr, "Could not initialize opengl: %s\n", SDL_GetError());
            return nullptr;
        }

        gladLoadGLLoader(SDL_GL_GetProcAddress);
        SDL_GL_SetSwapInterval(1);

        return window;
    }

    // void change_window_display(Window *window) {}

    void destroy_window(Window *window)
    {
        SDL_DestroyWindow(window->sdl_window);
        SDL_Quit();

        delete window;
    }

    void poll_next_event(Window *window) { SDL_PollEvent(&window->event_buffer); }
} // namespace Platform
