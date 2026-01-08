#include <opencv2/opencv.hpp>

int main(int argc, const char *argv[])
{
    cv::Mat image, imagecolor;

    // Carregando a imagem em escala de cinza
    image = imread(argv[1], cv::IMREAD_GRAYSCALE);
    if (!image.data)
    {
        std::cout << "nao abriu a imagem" << std::endl;
    }

    // Aplicando o colormap JET: cada valor de cinza sera mapeado para uma cor colorida do espectro JET
    cv::applyColorMap(image, imagecolor, cv::COLORMAP_JET);

    // Exibindo a imagem colorida
    cv::imshow("colormap_jet", imagecolor);
    cv::waitKey(0);

    return 0;
}