# Guia de Compilação

## Windows

Instale o [CMake](https://cmake.org/download/) e o [MSYS 2](https://www.mingw-w64.org/getting-started/msys2/)

Em seguida, dentro do MSYS2 UCRT CLI, instale os pacotes necessários

```bash
pacman -Syu

pacman -S mingw-w64-ucrt-x86_64-cmake \
    mingw-w64-ucrt-x86_64-ninja \ 
    mingw-w64-ucrt-x86_64-gcc \
    mingw-w64-ucrt-x86_64-opencv \
    mingw-w64-ucrt-x86_64-gdb \
    mingw-w64-ucrt-x86_64-qt6
```

Não se esqueça de adicionar o camniho **C:\msys64\ucrt64\bin** ao seu PATH

### Compilação do conteúdo e dos exercícios

Para compilar as implementações dos capítulos, execute os comandos abaixo no PowerShell

```bash
mkdir -p conteudo/build

# Buildar arquivos
cmake -G Ninja -B conteudo/build conteudo

# Gerar executaveis
cmake --build conteudo/build
```

Para compilar os exercícios, execute os comandos abaixo no PowerShell

```bash
mkdir -p exercicios/build

# Buildar arquivos
cmake -G Ninja -B exercicios/build exercicios

# Gerar executaveis
cmake --build exercicios/build
```

### Debug no VSCode

```bash
mkdir -p .vscode

cp .vscode.win/* .vscode
```

## Linux

...

## MacOS

...