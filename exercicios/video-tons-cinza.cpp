#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    cv::VideoCapture cap;
    cv::Mat frame;
    double width, height;
    int counter;

    cap.open(argv[1]);
    if (!cap.isOpened())
        return -1;

    width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);

    cv::Size frameSize(static_cast<int>(width), static_cast<int>(height));
    int type = cap.get(cv::CAP_PROP_FOURCC);
    cv::VideoWriter out("video-tons-cinza.avi", type, cap.get(cv::CAP_PROP_FPS), frameSize, true);

    for (counter = 0; cap.read(frame); counter++)
    {
        cv::Mat grayFrame;

        // Converter para tons de cinza (1 canal apenas)
        cv::cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);

        // Converter para BGR para manter o mesmo número de canais
        cv::cvtColor(grayFrame, grayFrame, cv::COLOR_GRAY2BGR);

        // Escrever frame
        out.write(grayFrame);

        if (cv::waitKey(30) >= 0)
            break;
    }

    return 0;
}