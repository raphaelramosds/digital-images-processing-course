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
    cv::VideoWriter out("video-negativo.avi", type, cap.get(cv::CAP_PROP_FPS), frameSize, true);

    for (counter = 0; cap.read(frame); counter++)
    {
        cv::Mat negativeFrame;
    
        // Aplicar efeito de negativo (inversao de bits nos canais)
        cv::bitwise_not(frame, negativeFrame);        

        // Escrever frame
        out.write(negativeFrame);

        if (cv::waitKey(30) >= 0)
            break;
    }

    return 0;
}