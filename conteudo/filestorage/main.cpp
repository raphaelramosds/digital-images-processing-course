#include <iostream>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <string>

int SIDE = 256;
int PERIODOS = 8;

int main(int argc, char **argv)
{
    std::stringstream ss_yml, ss_img;
    cv::Mat image;
    
    // Escrita no arquivo YAML da definicao da onda (ss_yml)
    // 1. Definicao do nome do arquivo
    ss_yml << "senoide-" << SIDE << ".yml";

    // 2. Inicializacao de uma matriz 256x256 com zeros (0.0)
    image = cv::Mat::zeros(SIDE, SIDE, CV_32FC1);

    // 3. Abrir stream de escrita
    cv::FileStorage fs(ss_yml.str(), cv::FileStorage::WRITE);

    // 4. Percorrer a matriz atribuindo valores entre 1.0 e 255.0 de acordo com a oscilacao da funcao seno
    for (int i = 0; i < SIDE; i++)
    {
        for (int j = 0; j < SIDE; j++)
        {
            image.at<float>(i, j) = 127 * sin(2 * M_PI * PERIODOS * j / SIDE) + 128;
        }
    }

    // 5. Escrita da matriz no arquivo YAML
    fs << "mat" << image;
    fs.release();

    // Escrita no arquivo PNG (ss_img)
    // 1. Normaliza os valores para o intervalo 0-255 (uint8)
    cv::normalize(image, image, 0, 255, cv::NORM_MINMAX);

    // 2. Converte para uint8
    image.convertTo(image, CV_8U);

    // 3. Definicao do nome do arquivo
    ss_img << "senoide-" << SIDE << ".png";

    // 4. Escrita da imagem no arquivo PNG
    cv::imwrite(ss_img.str(), image);

    // Interpretacao da definicao da senoide
    // 1. Abre arquivo ss_yml para leitura
    fs.open(ss_yml.str(), cv::FileStorage::READ);

    // 2. Carrega a matriz
    fs["mat"] >> image;

    // 3. Normaliza os valores para o intervalo 0-255 (uint8)
    cv::normalize(image, image, 0, 255, cv::NORM_MINMAX);

    // 4. Converte para uint8
    image.convertTo(image, CV_8U);

    cv::imshow("image", image);
    cv::waitKey();

    return 0;
}