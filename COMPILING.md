# Guia de Compilação

## Compilação no Windows com MSYS2 UCRT

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

No Powershell, compile o projeto

```bash
mkdir -p build

cmake -G Ninja -B build

cmake --build build
```

## Configurar debug no VSCode

### Windows

```bash
mkdir .vscode

cp .vscode.win .vscode
```