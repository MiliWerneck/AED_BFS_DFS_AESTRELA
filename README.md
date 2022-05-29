# Comparativo DFS - BFS - A* (Heurística Euclidiana e Manhattan)
## Introdução
<p align = "justify"> 
  Na primeira etapa do problema do labirinto, foi feita a implementação dos algoritmos <a href = "https://github.com/Nerd100oculoS/labirinto-BFS-DFS-etapa1"> BFS e DFS</a> para encontrar a saída. Agora, nesta segunda e ultima etapa, foi desenvolvido um novo algoritmo, derivado do BFS. Chamado de A*, no qual, foi empregado a Heurística Euclidiana e a Heurística de Manhattan para encontrar o menor caminho até a saída do labirinto. Por fim, há uma análise e uma comparação com todos os resultados obtidos na execução.<br> Conforme na etapa 1, nesta etapa também foi utilizado apenas as estruturas básicas dos respectivos repositórios, <a href = "https://github.com/mpiress/dynamic_list">Lista Dinâmica</a>, <a href = "https://github.com/mpiress/dynamic_stack">Pilha Dinâmica</a> e <a href = "https://github.com/mpiress/dynamic_queue">Fila Dinâmica</a> do professor <a href ="https://github.com/mpiress">Michel Pires</a>.
</p>

$$ DistânciaEuclidiana (x, y) = \sqrt{(x_{1} - x_{2})^2 + (y_{1} - y_{2})^2}$$

$$ DistânciaManhattan (x, y) = |x_{1} - x_{2}| + |y_{1} - y_{2}|$$



## Lógica

<p align = "justify">
  Tanto a Heurística de Manhattan quanto a Heurística Euclidiana utilizam o código do BFS da estapa 1 - Com algumas modificações. Para realizar a implementação destas heurísticas, fez-se necessario a criação de duas funções para cada. Cujo, uma faz o cálculo por meio da raiz
</p>

# Compilação e Execução

Makefile realiza o procedimento de compilação e execução.

|Comando| Funcao|
|----|----|
|`make clean`|Limpa tudo|
|`make r`|Executa a compilação utilizando gcc e executa o programa da pasta build após a realização da compilação.|

