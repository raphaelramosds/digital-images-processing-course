#include <iostream>
#include <opencv2/opencv.hpp>

int main(int, char**) {
    cv::Mat image;
    cv::Vec3b val; // alias para cv::Vec<unsigned char, 3> (vetor com tres entradas do tipo char nao sinalizado)

    std::string bolhas_path = "C:/Users/Raphael/Documents/Processamento-Digital-Imagens-Curso/pixels/bolhas.png";

    // Transformar figura em monocromatica: entradas de 1 byte que guardam tons de cinza
    image = cv::imread(bolhas_path, cv::IMREAD_GRAYSCALE);

    if (!image.data) std::cout << "nao abriu bolhas.png" << std::endl;

    cv::namedWindow("janela", cv::WINDOW_AUTOSIZE);

    // Desenhar uma linha preta
    for (int i = 200; i < 210; i++) {
        for (int j = 10; j < 200; j++) {
            // na entrada (i,j) grave a cor preta
            image.at<uchar>(i, j) = 0;
        }
    }

    cv::imshow("janela", image);
    cv::waitKey();

    // Transformar figura em policromatica: entradas de 3 bytes que guardam componentes RGB
    image = cv::imread(bolhas_path, cv::IMREAD_COLOR);

    val[0] = 0;    // B (1 byte)
    val[1] = 0;    // G (1 byte)
    val[2] = 255;  // R (1 byte)

    // Desenhar uma linha vermelha
    for (int i = 200; i < 210; i++) {
        for (int j = 10; j < 200; j++) {
            // na entrada (i,j) grave a cor vermelha
            image.at<cv::Vec3b>(i, j) = val;
        }
    }

    cv::imshow("janela", image);
    cv::waitKey();
    return 0;
}
