#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

int main(int argc, char **argv)
{
    cv::Mat image;
    cv::Mat hsv, rgb, h, s, v;

    std::vector<cv::Mat> planes;
    int camera;
    double min, max;

    if (argc != 2)
    {
        std::cerr << "Uso: " << argv[0] << " <Image_Path>\n";
        return -1;
    }

    // Carregando a imagem colorida
    image = cv::imread(argv[1], cv::IMREAD_COLOR);

    if (!image.data)
    {
        std::cerr << "Nao abriu " << argv[1] << std::endl;
        return -1;
    }

    // Exibindo a imagem original
    cv::namedWindow("image", cv::WINDOW_NORMAL);
    cv::imshow("image", image);

    // Separar os canais R, G e B e plota-los lado a lado
    cv::split(image, planes);
    cv::hconcat(planes[0], planes[1], rgb); // Concatene os canais R e G e salve em rgb temporariamente
    cv::hconcat(rgb, planes[2], rgb); // Concatene o canal B e salve em rgb
    cv::imshow("rgb", rgb);

    // Converter para o espaço de cores de RGB para HSV (8 bits por canal: 0 a 255)
    cv::cvtColor(image, image, cv::COLOR_BGR2HSV_FULL);

    // Separar os canais H, S, e V e plota-los lado a lado
    cv::split(image, planes);
    cv::hconcat(planes[0], planes[1], hsv);
    cv::hconcat(hsv, planes[2], hsv);
    cv::imshow("hsv", hsv);

    // Aplicar colormap HSV no primeiro canal (H)
    // Observe como cores principais de cada objeto são destacadas
    cv::applyColorMap(planes[0], h, cv::COLORMAP_HSV); // Aplicando o colormap HSV no planes[0] e salvando em h
    cv::imshow("h", h);

    cv::waitKey();
}