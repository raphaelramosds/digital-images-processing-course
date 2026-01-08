# Processamento Digital de Imagens

## Visão geral

Boa parte dos códigos e recursos utilizados nesse repositório são adaptações do material presente no curso [**Introdução ao processamento de imagens com OpenCV de Agostinho Brito**](https://agostinhobritojr.github.io/tutorial/pdi/).

[![DOCS](https://img.shields.io/badge/DOCS-4B0082?style=flat-square&logo=read-the-docs&logoColor=white)](./COMPILING.md) **Instruções 
de compilação**
- Guia passo a passo para compilar e debugar os códigos presentes nesse repositório no Windows, Linux e MacOS.

## Conteúdo

### Parte 1 - Representação e Manipulação de Imagens

#### Capítulo 1 - Conceitos iniciais

[![CXX](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)](./conteudo/hello/main.cpp) **Hello, OpenCV**

- Programa em OpenCV para carregar e exibir uma imagem
- Introdução da classe Mat e principais funções de I/O

#### Capítulo 2 - Manipulando pixels em uma imagem

[![CXX](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)](./conteudo/pixels/main.cpp) **Descrição do programa pixels**

- Acesso e manipulação direta dos pixels de uma imagem
- Apresentação dos conceitos de canais de cor e representação em tons de cinza

[![CXX](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)](./conteudo/labeling/main.cpp) **Descrição do programa labeling**

- Aplicação do algoritmo de rotulagem para identificar e manipular regiões conectadas em imagens binárias

[![Exercicio](https://img.shields.io/badge/Exercicio-yellow?style=flat-square)](./exercicios/regions.cpp) **Negativo de uma região**

- Exercício para criar o negativo de uma região específica em uma imagem colorida

[![Exercicio](https://img.shields.io/badge/Exercicio-yellow?style=flat-square)](./exercicios/trocaregioes.cpp) **Troca de regiões**

- Exercício para trocar os quadrantes de uma imagem

#### Capítulo 3 - Tratando arquivos de vídeo

[![CXX](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)](./conteudo/video/main.cpp) **Descrição do programa video**

- Capturar e exibir quadros de um arquivo de vídeo

[![Exercicio](https://img.shields.io/badge/Exercicio-yellow?style=flat-square)](./exercicios/video-tons-cinza.cpp) **Video em tons de cinza**

- Exercício para converter um vídeo colorido em tons de cinza

[![Exercicio](https://img.shields.io/badge/Exercicio-yellow?style=flat-square)](./exercicios/video-negativo.cpp) **Video com filtro negativo**

- Exercício para aplicar o efeito negativo em um vídeo

#### Capítulo 4 - Visualização de Imagens

[![CXX](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)](./conteudo/visualizacao/main.cpp) **Descrição do programa visualizacao**

- Geração de arquivos de texto com matrizes de intensidade de pixels e gráficos de linhas centrais de intensidade
- Utilização do gnuplot para visualização dos dados gerados

[![Exercicio](https://img.shields.io/badge/Exercicio-yellow?style=flat-square)](./exercicios/visualizacao/README.md) **Comparação gráfica de imagens com iluminações diferente**

- Exercício para gerar e comparar gráficos de intensidade de pixels de duas imagens com diferentes iluminações

#### Capítulo 5 - Serialização de dados em ponto flutuante via FileStorage

[![CXX](https://img.shields.io/badge/C++-00599C?style=flat-square&logo=C%2B%2B&logoColor=white)](./conteudo/filestorage/main.cpp) **Descrição do programa filestorage**

- Exemplos de como salvar e carregar dados em ponto flutuante utilizando a classe FileStorage do OpenCV
- Salvar e carregar imagens em formatos YAML e PNG

[![Exercicio](https://img.shields.io/badge/Exercicio-yellow?style=flat-square)](./exercicios/filestorage-senoides/README.md) **Gerar um padrão de interferência** 

- Exercício para gerar e salvar um padrão de interferência utilizando senoides em diferentes direções
- Visualizar o padrão salvo em um arquivo PNG
- O padrão foi resultado da substração de duas senoides perpendiculares