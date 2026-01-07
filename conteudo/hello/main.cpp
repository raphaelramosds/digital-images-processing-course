#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char** argv) {
    // Alocar objeto matriz
    Mat image;

    if (!argv[1]) {
        printf("Usage: ./hello <image>\n");
        exit(1);
    }

    // Converter imagem para escala de cinza
    image = imread(argv[1], IMREAD_GRAYSCALE);

    if (!image.data) {
        std::cout << "nao abriu " << argv[1] << std::endl;
    }

    std::cout << "tamanho: " << image.rows << "x" << image.cols << std::endl;

    // Exibir imagem numa janela do sistema operacional
    imshow("image", image);

    // Pressione qualquer tecla para sair
    cv::waitKey();

    return 0;
}
