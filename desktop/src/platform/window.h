#pragma once

namespace Platform
{
    struct Window;

    Window *init_window(const char *window_name);
    // void change_window_display(Window *window);
    void destroy_window(Window *window);

    struct WindowEvent
    {
    };

    void poll_next_event(Window *window);
} // namespace Platform
