# Analise-Algoritmos-de-Ordenacao
Análise com gráficos em Python de alguns algoritmos de ordenação implementados em C.

# Objetivo
O projeto visa proporcionar uma experiência prática com algoritmos de ordenação, analisando tanto a teoria quanto o desempenho real dos algoritmos com diferentes tamanhos de dados.

# Algoritmos Implementados
- Selection Sort: Seleciona o menor elemento e o move para a posição correta a cada iteração.
  Complexidade: O(n²)
- Insertion Sort: Constrói uma lista ordenada inserindo cada elemento na posição correta.
  Complexidade: O(n²) no pior caso, O(n) no melhor caso (lista quase ordenada)
- Bubble Sort: Compara e troca elementos adjacentes para ordenar a lista.
  Complexidade: O(n²) no pior caso, O(n) no melhor caso (lista ordenada)
- Merge Sort: Algoritmo eficiente que divide e conquista.
  Complexidade: O(n log n) em todos os casos
- Quick Sort: Divide a lista com um pivô.
  Complexidade: O(n log n) em média, O(n²) no pior caso (pivô mal escolhido)
- Heap Sort: Utiliza uma estrutura de heap para ordenar os elementos.
  Complexidade: O(n log n) em todos os casos

# Visualização
Gráficos foram gerados com Python para ilustrar o tempo de execução de cada algoritmo em relação ao tamanho da entrada.

# Como Rodar na sua IDE
1. Baixe algum compilador de C na sua máquina, (ex: MinGW) - Repo para Instalação: https://github.com/danielpinto8zz6/c-cpp-compile-run/blob/HEAD/docs/COMPILER_SETUP.md#Windows
2. No terminal digite "gcc .\src\sortingAlgorithms.c -o main" para compilar.
3. E "&.\main.exe" para executar.

# Autores

| [<img loading="lazy" src="https://avatars.githubusercontent.com/u/161663834?v=4" width=115><br><sub>Matheus Chagas</sub>](https://github.com/matheuschagasb) |  [<img loading="lazy" src="https://media.licdn.com/dms/image/v2/D4D35AQF_d_8dyx-N8A/profile-framedphoto-shrink_400_400/profile-framedphoto-shrink_400_400/0/1729019213896?e=1731891600&v=beta&t=Idd2_CqM_sM-BKIHNQzxtn6q29xTbIEEULu77z-VEC0" width=115><br><sub>Thiago Mauri</sub>](https://www.linkedin.com/in/thiago-mauri-gonzalez/) |  [<img loading="lazy" src="https://avatars.githubusercontent.com/u/116125017?v=4" width=115><br><sub>Victor Ramalho</sub>](https://github.com/RamalhoVr) |
| :---: | :---: | :---: |
