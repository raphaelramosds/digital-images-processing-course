# Processamento Digital de Imagens

## Compilação no Windows com MSYS2 UCRT

Instale o MSYS 2 (consulte https://www.mingw-w64.org/getting-started/msys2/)

Em seguida, dentro do MSYS2 UCRT CLI, instale os pacotes necessários

```bash
pacman -Syu

pacman -S mingw-w64-ucrt-x86_64-cmake \
    mingw-w64-ucrt-x86_64-ninja \ 
    mingw-w64-ucrt-x86_64-gcc \
    mingw-w64-ucrt-x86_64-opencv \
    mingw-w64-ucrt-x86_64-gdb
```

Não se esqueça de adicionar  (Path: C:\msys64\ucrt64\bin) ao seu PATH

No Powershell, compile o projeto

```bash
mkdir build && cd build

cmake -G Ninja .. 

cmake --build .
```
## Configurar debug no VSCode

### Windows

```bash
mkdir .vscode

cp .vscode.win .vscode
```