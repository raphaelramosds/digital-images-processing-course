# Guia de Compilação

## Windows

Instale o MSYS 2 (consulte https://www.mingw-w64.org/getting-started/msys2/)

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

Não se esqueça de adicionar  (Path: C:\msys64\ucrt64\bin) ao seu PATH

## Instruções de compilação

### Compilação do conteúdo

No Powershell, compile o projeto

```bash
mkdir -p conteudo/build

cmake -G Ninja -B conteudo/build conteudo

cmake --build conteudo/build
```

### Compilação dos exercícios

```bash
mkdir -p exercicios/build

cmake -G Ninja -B exercicios/build exercicios

cmake --build exercicios/build
```

## Configurar debug no VSCode

### Windows

```bash
mkdir -p .vscode

cp .vscode.win/* .vscode
```