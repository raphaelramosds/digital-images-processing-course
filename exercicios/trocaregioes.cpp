#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <image_path>" << std::endl;
        return -1;
    }

    cv::Mat image = cv::imread(argv[1]);

    if (image.empty()) {
        std::cerr << "Erro ao carregar a imagem!" << std::endl;
        return -1;
    }

    return 0;
}