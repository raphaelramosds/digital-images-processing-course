#include <iostream>
#include <opencv2/opencv.hpp>

void printUsage()
{
    std::cout << "Uso: ./regions <imagem> <x1> <y1> <x2> <y2>\n";
    std::cout << "Onde (x1, y1) e (x2, y2) definem o retangulo de interesse.\n";
}

int main(int argc, char **argv)
{
    int width, height;
    int x1, y1, x2, y2;

    if (argc < 6)
    {
        printUsage();
        return -1;
    }

    cv::Mat image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

    if (!image.data)
    {
        std::cout << "imagem nao carregou corretamente\n";
        return -1;
    }

    width = image.cols;
    height = image.rows;

    std::cout << "dimensoes da imagem: " << width << "x" << height << std::endl;

    x1 = std::atoi(argv[2]);
    y1 = std::atoi(argv[3]);
    x2 = std::atoi(argv[4]);
    y2 = std::atoi(argv[5]);

    if (x1 < 0 || x2 < 0) {
        std::cout << "coordenadas negativas\n";
    }
    
    if (x2 >= width || y2 >= height || x1 >= width || y1 >= height)
    {
        std::cout << "coordenadas ultrapassam dimensoes da imagem\n";
        return -1;
    }

    for (int i = y1; i <= y2; i++)
    {
        for (int j = x1; j <= x2; j++)
        {
            // Grava o complemento do pixel lido
            image.at<uchar>(i, j) = 255 - image.at<uchar>(i, j);
        }
    }

    cv::imshow("regioes invertidas", image);
    cv::waitKey(0);

    return 0;
}