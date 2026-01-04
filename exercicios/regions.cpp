#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    cv::Mat image = cv::imread("biel.png", cv::IMREAD_GRAYSCALE);
    cv::imshow("imagem", image);
    cv::waitKey(0);
    return 0;
}