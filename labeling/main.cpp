#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    cv::Mat image, realce;
    int width, height;
    int nobjects;

    cv::Point p;
    image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

    if (!image.data)
    {
        std::cout << "imagem nao carregou corretamente\n";
        return (-1);
    }

    width = image.cols;
    height = image.rows;
    std::cout << width << "x" << height << std::endl;

    p.x = 0;
    p.y = 0;

    // busca objetos presentes
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // encontrado um pixel branco, anote a posicao e rotule o objeto
            if (image.at<uchar>(i, j) == 255)
            {
                p.y = i;
                p.x = j;
                nobjects++;
                cv::floodFill(image, p, cv::Scalar(100 + nobjects));
            }
        }
    }

    cv::equalizeHist(image, realce);
    cv::imwrite("rotulada.png", image);
    cv::imwrite("rotulada_equalizada.png", realce);
    std::cout << "Numero de objetos: " << nobjects << std::endl;

    return 1;
}
