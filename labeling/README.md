# Algoritmo labeling

A seguir uma explicação sobre rotulagem de componentes conectados

1. O `for` encontra o primeiro pixel branco do primeiro objeto: `nobjects` vira 1.
2. O `floodFill` pinta toda aquela forma branca com o valor 1. Agora, aquela forma não tem mais pixels de valor 255.
3. O `for` continua. Ele ignora os pixels pretos (0) e os pixels que agora são cinza-claro (1).
4. Eventualmente, ele encontra um pixel branco de um segundo objeto: `nobjects` vira 2.
5. O `floodFill` pinta toda essa segunda forma com o valor 2.

O processo se repete até que não haja mais pixels brancos (255) na imagem.

Utilizamos uma equalização para perceber melhor os tons de cinza na imagem rotulada, visto que o olho humano não consegue distinguir muitos tons de cinza próximos, por exemplo, de 5 a 8.