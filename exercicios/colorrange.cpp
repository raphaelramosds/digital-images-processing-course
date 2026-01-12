#include <iostream>
#include <opencv2/opencv.hpp>

cv::Mat originalImage;
cv::Mat displayImage;
cv::Mat selectionMask;  // Mascara que armazena quais pixels foram selecionados

cv::Scalar average;
cv::Scalar stdev;

int rangeR = 0;
int rangeG = 0;
int rangeB = 0;
int brushRadius = 10;
bool selectObject = false; // Flag para indicar se o usuario esta selecionando

void on_trackbar_R(int value, void *userdata) { rangeR = value; }
void on_trackbar_G(int value, void *userdata) { rangeG = value; }
void on_trackbar_B(int value, void *userdata) { rangeB = value; }
void on_trackbar_radius(int value, void *userdata) { brushRadius = std::max(1, value); }

static void onMouse(int event, int x, int y, int flags, void *)
{
    selectObject = false;
    
    // Verificar se coordenadas estão dentro da imagem
    if (x < 0 || x >= originalImage.cols || y < 0 || y >= originalImage.rows)
        return;

    if (event == cv::EVENT_MOUSEMOVE)
    {
        // Botão esquerdo pressionado: ADICIONAR pixels à seleção
        if (flags & cv::EVENT_FLAG_LBUTTON)
        {
            cv::circle(selectionMask, cv::Point(x, y), brushRadius, cv::Scalar(255), -1);
            selectObject = true;
        }
        // Botão direito pressionado: REMOVER pixels da seleção
        else if (flags & cv::EVENT_FLAG_RBUTTON)
        {
            cv::circle(selectionMask, cv::Point(x, y), brushRadius, cv::Scalar(0), -1);
            selectObject = true;
        }
    }
}

int main(int argc, const char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Uso: " << argv[0] << " <imagem>" << std::endl;
        return -1;
    }

    originalImage = cv::imread(argv[1]);
    if (originalImage.empty())
    {
        std::cerr << "Erro ao carregar imagem: " << argv[1] << std::endl;
        return -1;
    }

    // Inicializar mascara de selecao como zeros (nenhum pixel selecionado)
    selectionMask = cv::Mat::zeros(originalImage.size(), CV_8U);

    // Inicializar valores padrão
    average = cv::Scalar(128, 128, 128);
    stdev = cv::Scalar(0, 0, 0);

    cv::namedWindow("Image", cv::WINDOW_NORMAL);
    cv::namedWindow("Selection", cv::WINDOW_NORMAL);

    // Criar trackbars para ajustar a faixa de cores
    cv::createTrackbar("R-range", "Image", &rangeR, 255, on_trackbar_R, &rangeR);
    cv::createTrackbar("G-range", "Image", &rangeG, 255, on_trackbar_G, &rangeG);
    cv::createTrackbar("B-range", "Image", &rangeB, 255, on_trackbar_B, &rangeB);
    cv::createTrackbar("Raio do Pincel", "Image", &brushRadius, 50, on_trackbar_radius, &brushRadius);

    // Configurar callback do mouse
    cv::setMouseCallback("Image", onMouse, 0);

    cv::Mat colorMask;

    for (;;)
    {
        originalImage.copyTo(displayImage);
        char c = cv::waitKey(10);
        if (c == 27)  // ESC
        {
            break;
        }

        // Se houver pixels selecionados, calcular media e desvio padrao
        if (cv::countNonZero(selectionMask) > 0 && selectObject)
        {
            // Calcular estatísticas apenas dos pixels selecionados
            cv::meanStdDev(originalImage, average, stdev, selectionMask);

            // Atualizar trackbars com os valores calculados (3 * desvio padrao)
            rangeR = 3 * stdev[2];
            cv::setTrackbarPos("R-range", "Image", rangeR);
            rangeG = 3 * stdev[1];
            cv::setTrackbarPos("G-range", "Image", rangeG);
            rangeB = 3 * stdev[0];
            cv::setTrackbarPos("B-range", "Image", rangeB);

            std::cout << "Pixels selecionados: " << cv::countNonZero(selectionMask) << std::endl;
            std::cout << "Média: " << average << std::endl;
            std::cout << "Desvio Padrão: " << stdev << std::endl;
            std::cout << "Range mín: " << average - cv::Scalar(rangeB, rangeG, rangeR) << std::endl;
            std::cout << "Range máx: " << average + cv::Scalar(rangeB, rangeG, rangeR) << std::endl;
            std::cout << "---" << std::endl;
        }

        // Criar mascara de cores com base na faixa definida
        cv::inRange(originalImage,
                    average - cv::Scalar(rangeB, rangeG, rangeR),
                    average + cv::Scalar(rangeB, rangeG, rangeR),
                    colorMask);

        // Aplicar a mascara de selecao do usuario a imagem de saida
        // NOTE: Todos os pixels de greenOverlay sao (0,255,0) mas o copyTo apenas copia 
        // para a imagem de visualizacao os pixels onde selectionMask é nao nulo. E estes
        // pixels nao nulos sao aqueles que o usuario selecionou com o mouse.
        cv::Mat greenOverlay = cv::Mat::zeros(selectionMask.size(), CV_8UC3);
        greenOverlay.setTo(cv::Scalar(0, 255, 0));
        greenOverlay.copyTo(displayImage, selectionMask);

        cv::imshow("Image", displayImage);
        cv::imshow("Selection", colorMask);
    }

    // Salvar a mascara de cores resultante
    cv::imwrite("color_mask.png", colorMask);

    cv::destroyAllWindows();
    return 0;
}
