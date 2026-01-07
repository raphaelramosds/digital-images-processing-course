#include <iostream>
#include <fstream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace cv;

int main(int argc, char **argv)
{
    Mat image;
    std::ofstream file;

    // Converter imagem para escala de cinza (1 canal)
    image = imread(argv[1], cv::IMREAD_GRAYSCALE);
    if (!image.data)
    {
        std::cout << "imagem nao carregou corretamente\n";
        return (-1);
    }

    // Redimensionar para 128x128 (melhor visualizacao no gnuplot)
    cv::resize(image, image, Size(128, 128), 0, 0, INTER_LINEAR);

    // Escrever os valores de cada pixel da imagem em um arquivo texto
    // Plote este arquivo no gnuplot com os comandos dos arquivos: plotar_matrix.plt e plotar_3d.plt
    file.open("image.txt");
    for (int j = 0; j < image.rows; j++)
    {
        for (int i = 0; i < image.cols; i++)
        {
            file << (int)(image.at<uchar>(j, i)) << " ";
        }
        file << "\n";
    }
    file.close();

    // Escrever os valores dos pixels centrais da imagem em um arquivo texto
    // Plote este arquivo no gnuplot com o comando do arquivo: plotar_histeps.plt
    file.open("line.txt");
    for (int i = 0; i < image.cols; i++)
    {
        file << (int)(image.at<uchar>(image.rows / 2, i)) << "\n";
    }
    file.close();

    return 0;
}