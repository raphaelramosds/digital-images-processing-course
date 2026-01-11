#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat image;
bool selectObject = false;
int trackObject = 0;
cv::Point origin;
cv::Rect selection;

cv::Scalar average;
cv::Scalar stdev;

int rangeR = 0;
int rangeG = 0;
int rangeB = 0;

void on_trackbar_R(int value, void *userdata) { rangeR = value; }
void on_trackbar_G(int value, void *userdata) { rangeG = value; }
void on_trackbar_B(int value, void *userdata) { rangeB = value; }

static void onMouse(int event, int x, int y, int, void *)
{
    // Caso o usuario esteja selecionando uma regiao com o mouse
    if (selectObject)
    {
        // NOTE: (x,y) sao as coordenadas atuais do mouse

        // Garante que selection.x e selection.y sejam as coordenadas do canto superior esquerdo do retangulo de selecao
        selection.x = MIN(x, origin.x);
        selection.y = MIN(y, origin.y);

        // Calcula largura e altura da selecao de acordo com a posicao atual do mouse
        selection.width = std::abs(x - origin.x);
        selection.height = std::abs(y - origin.y);

        // Aplicar interseccao entre a selecao e a imagem para evitar estouro de limites
        // Em resumo, essa linha corta qualquer parte do retangulo de selecao que esteja fora da imagem
        selection &= cv::Rect(0, 0, image.cols, image.rows);
    }
    switch (event)
    {
    // Iniciar selecao com o botao esquerdo do mouse pressionado
    case cv::EVENT_LBUTTONDOWN:
    {
        // Comece a selecao da origem (x,y) e crie um retangulo de selecao vazio
        origin = cv::Point(x, y);
        selection = cv::Rect(x, y, 0, 0);
        selectObject = true;
        break;
    }
    // Finalizar selecao com o botao esquerdo do mouse soltado
    case cv::EVENT_LBUTTONUP:
    {
        selectObject = false;
        if (selection.width > 0 && selection.height > 0)
        {
            // Usuario terminou a selecao
            trackObject = 1;
        }
        break;
    }
    }
}

int main(int argc, const char **argv)
{
    cv::Rect trackWindow;
    cv::Mat mask;
    cv::Mat frame;
    frame = cv::imread(argv[1]);

    average = cv::Scalar(128, 128, 128);
    stdev = cv::Scalar(0, 0, 0);

    cv::namedWindow("Image", cv::WINDOW_NORMAL);
    cv::namedWindow("Selection", cv::WINDOW_NORMAL);
    cv::createTrackbar("R-range", "Image", &rangeR, 255, on_trackbar_R, &rangeR);
    cv::createTrackbar("G-range", "Image", &rangeG, 255, on_trackbar_G, &rangeG);
    cv::createTrackbar("B-range", "Image", &rangeB, 255, on_trackbar_B, &rangeB);

    // Configurar callback para monitorar eventos do mouse na janela "Image" (onde o usuario seleciona a regiao)
    cv::setMouseCallback("Image", onMouse, 0);

    for (;;)
    {
        frame.copyTo(image);
        char c = cv::waitKey(10);
        if (c == 27)
        {
            // Sair do programa se a tecla ESC for pressionada
            break;
        }
        if (selectObject && selection.width > 0 && selection.height > 0)
        {
            // Criar Regiao de Interesse (ROI - Region of Interest) com base no retangulo selecionado
            cv::Mat roi(image, selection);

            // Inverter pixels da ROI (apenas para visualizacao da selecao)
            cv::bitwise_not(roi, roi);
        }
        cv::imshow("Image", image);
        if (trackObject)
        {
            // Quando o usuario terminar a selecao com o mouse, calcular a media e o desvio padrao da regiao selecionada
            // OBS: stdev eh um vetor com 3 elementos (um para cada canal de cor BGR)
            if (!selectObject && selection.width > 0 && selection.height > 0)
            {
                cv::Mat roi(image, selection);
                cv::meanStdDev(roi, average, stdev);
                rangeR = 3 * stdev[2];
                cv::setTrackbarPos("R-range", "Image", rangeR);
                rangeG = 3 * stdev[1];
                cv::setTrackbarPos("G-range", "Image", rangeG);
                rangeB = 3 * stdev[0];
                cv::setTrackbarPos("B-range", "Image", rangeB);
                std::cout << "Average: " << average << std::endl;
                std::cout << "Range min: "
                          << average - cv::Scalar(rangeB, rangeG, rangeR) << std::endl;
                std::cout << "Range min: "
                          << average + cv::Scalar(rangeB, rangeG, rangeR) << std::endl;
            }
            trackObject = 0;
        }
        // Seleciona os pixels dentro da faixa de cores (media - 3*desvio, media + 3*desvio)
        cv::inRange(image, average - cv::Scalar(rangeB, rangeG, rangeR),
                    average + cv::Scalar(rangeB, rangeG, rangeR), mask);
        
        // Mostrar a mascara resultante com os pixels selecionados
        cv::imshow("Selection", mask);
    }
    cv::imwrite("selection.png", mask);
    return 0;
}