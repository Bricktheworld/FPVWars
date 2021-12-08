#include <types.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <platform/window.h>

int main(int argc, char **argv)
{
    Platform::Window *window;

    cv::VideoCapture capture(0);

    ASSERT(capture.isOpened(), "Unable to open video camera capture!");

    cv::Mat frame;

    // auto frame_dimensions = Vec2(capture.get(cv::CAP_PROP_FRAME_WIDTH), capture.get(cv::CAP_PROP_FRAME_HEIGHT));

    SDL_PollEvent(&event);
    int w, h;
    SDL_GetWindowSize(window, &w, &h);

    while (event.type != SDL_QUIT)
    {
      while(SDL_PollEvent(&event) {

      }
        capture.read(frame);

        glViewport(0, 0, w, h);
        glClearColor(0.5, 0.5, 0.5, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        SDL_GL_SwapWindow(window);
    }

    capture.release();

    // cv::destroyAllWindows();

    return 0;
}
