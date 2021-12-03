#include <types.h>
#include <stdio.h>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    cv::VideoCapture capture(0);

    ASSERT(capture.isOpened(), "Unable to open video camera capture!");

    cv::Mat frame;

    auto frame_dimensions = Vec2(capture.get(cv::CAP_PROP_FRAME_WIDTH), capture.get(cv::CAP_PROP_FRAME_HEIGHT));

    while (capture.read(frame))
    {
        cv::imshow("FPVWars", frame);

        if (cv::waitKey(25) >= 0)
        {
            break;
        }
    }

    capture.release();

    cv::destroyAllWindows();

    return 0;
}
