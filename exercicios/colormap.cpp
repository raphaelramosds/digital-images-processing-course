#include <opencv2/opencv.hpp>

enum MyColorMapTypes
{
    MY_COLORMAP_SIMPLE = 100,
    MY_COLORMAP_LUT = 101
};

// Exemplo de função de colormap customizado mapeando pixel a pixel
void applySimpleColorMap(const cv::Mat &grayImage, cv::Mat &colorImage)
{
    // Cria imagem colorida com 3 canais e mesmo tamanho da imagem com tons de cinza
    colorImage.create(grayImage.size(), CV_8UC3);

    // Para cada pixel da imagem em tons de cinza, mapeia para uma cor na imagem colorida
    for (int i = 0; i < grayImage.rows; ++i)
    {
        for (int j = 0; j < grayImage.cols; ++j)
        {
            uchar pixelValue = grayImage.at<uchar>(i, j);
            cv::Vec3b &colorPixel = colorImage.at<cv::Vec3b>(i, j);

            // Exemplo simples de mapeamento: do azul ao vermelho
            colorPixel[0] = ((1 << 8) - 1) - pixelValue; // B
            colorPixel[1] = 0;                           // G
            colorPixel[2] = pixelValue;                  // R
        }
    }
}

// Exemplo função de colormap customizado mapeando com cv::LUT
// WONTFIX
void applyLUTColorMap(const cv::Mat &grayImage, cv::Mat &colorImage)
{
    if (grayImage.empty() || grayImage.type() != CV_8UC1)
    {
        std::cout << "Erro: A imagem deve ser CV_8UC1 (tons de cinza de 8 bits)." << std::endl;
        return;
    }

    // Cria uma look-up table (LUT) para mapear cada tom de cinza (0 a 255) para uma cor (3 canais com 8 bits)
    // NOTE: a LUT eh um vetor de 256 elementos, e cada cada elemento eh um Vec3b (BGR)
    std::cout << "Criando LUT personalizada..." << std::endl;
    cv::Mat lut(256, 1, CV_8UC3);
    uint16_t i;

    for (i = 0; i < 256; ++i)
    {
        // Cada tom de cinza eh mapeado para uma cor BGR tal que:
        // As componentes azul (i) e vermelha (i/2) variem inversamente com a verde (255-i)
        lut.at<cv::Vec3b>(0) = cv::Vec3b(
            static_cast<uchar>(i),
            static_cast<uchar>(255 - i),
            static_cast<uchar>(i / 2)); // Formato BGR
    }
    std::cout << "LUT criada." << std::endl;

    // Aplica a LUT na imagem em tons de cinza para obter a imagem colorida
    cv::LUT(grayImage, lut, colorImage);
    std::cout << "LUT aplicada na imagem." << std::endl;
}

void displayWithColorMap(const cv::Mat &image, int colormap_type, const std::string &window_name)
{
    cv::Mat imagecolor;

    switch (colormap_type)
    {
    case MY_COLORMAP_SIMPLE:
        applySimpleColorMap(image, imagecolor);
        break;
    case MY_COLORMAP_LUT:
        applyLUTColorMap(image, imagecolor);
        break;
    default:
        cv::applyColorMap(image, imagecolor, colormap_type);
        break;
    }

    cv::imshow(window_name, imagecolor);
    cv::waitKey(0);
}

int main(int argc, const char *argv[])
{
    cv::Mat image, imagecolor;

    // Carregando a imagem em escala de cinza
    image = imread(argv[1], cv::IMREAD_GRAYSCALE);
    if (!image.data)
    {
        std::cout << "nao abriu a imagem" << std::endl;
        return -1;
    }

    // Colormaps customizados
    // displayWithColorMap(image, MY_COLORMAP_LUT, "My LUT Colormap");
    displayWithColorMap(image, MY_COLORMAP_SIMPLE, "My Simple Colormap");

    // NOTE: cv::ColormapsTypes do OpenCV disponiveis: https://docs.opencv.org/4.x/d3/d50/group__imgproc__colormap.html
    displayWithColorMap(image, cv::COLORMAP_AUTUMN, "Autumn");
    displayWithColorMap(image, cv::COLORMAP_BONE, "Bone");
    displayWithColorMap(image, cv::COLORMAP_DEEPGREEN, "Deep Green");
    displayWithColorMap(image, cv::COLORMAP_HSV, "HSV");
    displayWithColorMap(image, cv::COLORMAP_INFERNO, "Inferno");

    return 0;
}