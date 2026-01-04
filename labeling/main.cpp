#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    cv::Mat image, realce;
    int width, height;
    int nobjects = 0;

    cv::Point p;
    image = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);

    if (!image.data)
    {
        std::cout << "Imagem nao carregou corretamente\n";
        return (-1);
    }

    width = image.cols;
    height = image.rows;
    std::cout << width << "x" << height << std::endl;

    p.x = 0;
    p.y = 0;

    // Busca objetos presentes
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image.at<uchar>(i, j) == 255)
            {
                // Achou um objeto
                nobjects++;
                p.y = i;
                p.x = j;

                // Preenche o objeto com o contador
                cv::floodFill(image, p, nobjects);
            }
            // Segue para procurar o proximo pixel branco
        }
    }

    cv::equalizeHist(image, realce);
    cv::imwrite("rotulada.png", image);
    cv::imwrite("rotulada_equalizada.png", realce);
    std::cout << "Numero de bolhas: " << nobjects << std::endl;

    return 1;
}
