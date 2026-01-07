#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv)
{
    // A classe VideoCapture é usada para lidar com arquivos e dispositivos de video
    cv::VideoCapture cap;
    cv::Mat frame;

    // Dimensoes dos frames
    double width, height;

    // Contador de frames
    int counter;

    // Abre o arquivo de video passado como argumento na linha de comando
    cap.open(argv[1]);
    if (!cap.isOpened())
        return -1;

    width = cap.get(cv::CAP_PROP_FRAME_WIDTH);
    height = cap.get(cv::CAP_PROP_FRAME_HEIGHT);
    std::cout << "largura=" << width << "\n";
    std::cout << "altura =" << height << "\n";

    // Define o tamanho dos frames do video de saida
    cv::Size frameSize(static_cast<int>(width), static_cast<int>(height));

    // Recuperar o tipo de codec (Algoritmo usado para codificar o arquivo de video)
    int type = cap.get(cv::CAP_PROP_FOURCC);

    // Abrir stream para escrita do video de saida
    // OBS: o "true" no ultimo argumento serve para indicar que o video é colorido
    cv::VideoWriter out("output.avi", type, cap.get(cv::CAP_PROP_FPS), frameSize, true);

    // Escrever cada frame
    for (counter = 0; cap.read(frame); counter++)
    {
        out << frame;
        cv::imshow("Frame", frame);
        if (cv::waitKey(30) >= 0)
            break;
    }
    std::cout << "Numero de frames: " << counter << "\n";
    return 0;
}