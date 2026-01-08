#include <iostream>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <string>

int SIDE = 256;

void gerar_senoide_horizontal(cv::Mat &image, int periodos)
{
    int i, j;

    for (i = 0; i < SIDE; i++)
    {
        for (j = 0; j < SIDE; j++)
        {
            image.at<float>(j, i) = 127 * sin(2 * M_PI * periodos * j / SIDE) + 128;
        }
    }
}

void gerar_senoide_vertical(cv::Mat &image, int periodos)
{
    int i, j;

    for (i = 0; i < SIDE; i++)
    {
        for (j = 0; j < SIDE; j++)
        {
            image.at<float>(i, j) = 127 * sin(2 * M_PI * periodos * j / SIDE) + 128;
        }
    }
}

void escreve_yaml(const std::string &filename, const cv::Mat &image)
{
    std::stringstream ss;
    ss << filename << ".yml";
    cv::FileStorage fs(ss.str(), cv::FileStorage::WRITE);
    fs << "mat" << image;
    fs.release();
}

void escreve_png(const std::string &filename, const cv::Mat &image)
{
    std::stringstream ss;
    ss << filename << ".png";
    cv::Mat img_uint8;
    cv::normalize(image, img_uint8, 0, 255, cv::NORM_MINMAX);
    img_uint8.convertTo(img_uint8, CV_8U);
    cv::imwrite(ss.str(), img_uint8);
}

int main(int argc, char **argv)
{
    cv::Mat mat_senoide_horizontal = cv::Mat::zeros(SIDE, SIDE, CV_32F);
    cv::Mat mat_senoide_vertical = cv::Mat::zeros(SIDE, SIDE, CV_32F);
    cv::Mat diferencas = cv::Mat::zeros(SIDE, SIDE, CV_32F);

    gerar_senoide_horizontal(mat_senoide_horizontal, 4);
    // escreve_yaml("senoide-horizontal-256", mat_senoide_horizontal);
    escreve_png("senoide-horizontal-256", mat_senoide_horizontal);

    gerar_senoide_vertical(mat_senoide_vertical, 8);
    // escreve_yaml("senoide-vertical-256", mat_senoide_vertical);
    escreve_png("senoide-vertical-256", mat_senoide_vertical);

    // Calcular e exibir diferencas
    cv::absdiff(mat_senoide_horizontal, mat_senoide_vertical, diferencas);
    escreve_png("diferencas-senoides-256", diferencas);

    return 0;
}