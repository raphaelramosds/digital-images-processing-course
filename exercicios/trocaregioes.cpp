#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <imagem>" << std::endl;
        return -1;
    }

    cv::Mat image = cv::imread(argv[1]);

    if (image.empty()) {
        std::cerr << "Erro ao carregar a imagem!" << std::endl;
        return -1;
    }

    // Extrair submatriz: sobrecargar do operador () da classe Mat
    // Mat cv::Mat::operator()	(	Range	rowRange, Range	colRange ) const

    // Copiar quadrantes da imagem
    cv::Mat q1 = image(cv::Range(0, image.rows/2), cv::Range(0, image.cols/2)).clone();
    cv::Mat q2 = image(cv::Range(0, image.rows/2), cv::Range(image.cols/2, image.cols)).clone();
    cv::Mat q3 = image(cv::Range(image.rows/2, image.rows), cv::Range(0, image.cols/2)).clone();
    cv::Mat q4 = image(cv::Range(image.rows/2, image.rows), cv::Range(image.cols/2, image.cols)).clone();

    // Trocar quadrantes q1 com q4
    q1.copyTo(image(cv::Range(image.rows/2, image.rows), cv::Range(image.cols/2, image.cols)));
    q4.copyTo(image(cv::Range(0, image.rows/2), cv::Range(0, image.cols/2)));

    // Trocar quadrantes q2 com q3
    q2.copyTo(image(cv::Range(image.rows/2, image.rows), cv::Range(0, image.cols/2)));
    q3.copyTo(image(cv::Range(0, image.rows/2), cv::Range(image.cols/2, image.cols)));
    
    cv::imshow("trocaregioes", image);
    cv::waitKey(0);

    return 0;
}