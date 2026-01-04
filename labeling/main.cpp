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
            if (image.at<uchar>(i, j) == 255)
            {
                // achou um objeto
                nobjects++;
                p.y = i;
                p.x = j;

                // preenche o objeto com o contador
                cv::floodFill(image, p, nobjects);
            }
            // segue para procurar o proximo pixel branco
        }
    }

    cv::equalizeHist(image, realce);
    cv::imwrite("rotulada.png", image);
    cv::imwrite("rotulada_equalizada.png", realce);
    std::cout << "Numero de bolhas: " << nobjects << std::endl;

    return 1;
}
