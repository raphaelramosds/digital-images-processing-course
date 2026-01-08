# Processamento Digital de Imagens

## Visão geral

Boa parte dos códigos e recursos utilizados nesse repositório são adaptações do material presente no curso [**Introdução ao processamento de imagens com OpenCV de Agostinho Brito**](https://agostinhobritojr.github.io/tutorial/pdi/).

## Conteúdo

[![DOCS](https://img.shields.io/badge/DOCS-4B0082?style=flat-square&logo=read-the-docs&logoColor=white)](./COMPILING.md) **Instruções de compilação**
- Guia passo a passo para compilar e debugar os códigos presentes nesse repositório no Windows

[![CXX](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)](./conteudo/hello) **Hello, OpenCV**

- Simples programa em C++ que carrega e exibe uma imagem utilizando a biblioteca OpenCV.

[![CXX](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)](./conteudo/labeling) **Labeling**

- Implementação do algoritmo de rotulagem de componentes conectados (labeling) em imagens binárias.

[![CXX](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)](./conteudo/pixels) **Manipulando pixels em uma imagem**

- Exemplos de como acessar e modificar os valores dos pixels em uma imagem

[![CXX](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)](./conteudo/video) **Tratando arquivos de vídeo**

- Exemplos de como capturar, processar e exibir frames de um vídeo utilizando OpenCV.

[![CXX](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)](./conteudo/visualizacao) **Visualização de Imagens**
- Exemplos de formas de visualização de uma imagem em tons de cinza utilizando: formato matricial, plot 3D e linha central

[![CXX](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)](./conteudo/filestorage/) **Serialização de dados em ponto flutuante via FileStorage**

- Exemplos de como salvar e carregar dados em ponto flutuante utilizando a classe FileStorage do OpenCV
- Salvar e carregar imagens em formatos YAML e PNG

## Exercicios

### Parte I

#### Representação de Imagens - Capitulo 2

- regions.cpp
- trocaregioes.cpp

#### Tratando arquivos de vídeo - Capitulo 3

- video-tons-de-cinza.cpp
- video-negativo.cpp

### Visualização de Imagens - Capitulo 4

- [visualizacao](./exercicios/visualizacao/README.md)

### Serialização de dados em ponto flutuante via FileStorage - Capitulo 5

- [filestorage-senoides](./exercicios/filestorage-senoides/README.md)