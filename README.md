# Comparativo DFS - BFS - A* (Heurística Euclidiana e  Heurística de Manhattan)
## Introdução
<p align = "justify"> 
  Na primeira etapa do problema do labirinto, foi feita a implementação dos algoritmos <a href = "https://github.com/Nerd100oculoS/labirinto-BFS-DFS-etapa1"> BFS e DFS</a> para encontrar a saída. Agora, nesta segunda e ultima etapa, foi desenvolvido um novo algoritmo, derivado do BFS. Chamado de A*, no qual, foi empregado a Heurística Euclidiana e a Heurística de Manhattan para encontrar o menor caminho até a saída do labirinto. Por fim, há uma análise e uma comparação com todos os resultados obtidos na execução.<br> Conforme na etapa 1, nesta etapa também foi utilizado apenas as estruturas básicas dos respectivos repositórios, <a href = "https://github.com/mpiress/dynamic_list">Lista Dinâmica</a>, <a href = "https://github.com/mpiress/dynamic_stack">Pilha Dinâmica</a> e <a href = "https://github.com/mpiress/dynamic_queue">Fila Dinâmica</a> do professor <a href ="https://github.com/mpiress">Michel Pires</a>. Logo abaixo, estão as duas formúlas matematicas referentes as heurísticas utilizadas.<br>
</p>

$$ DistânciaEuclidiana (x, y) = \sqrt{(x_{1} - x_{2})^2 + (y_{1} - y_{2})^2}$$

$$ DistânciaManhattan (x, y) = |x_{1} - x_{2}| + |y_{1} - y_{2}|$$

## Lógica

<p align = "justify">
Tanto a Heurística de Euclidiana quanto a Heurística Manhattan utilizam o código BFS da estapa 1 - Com algumas modificações. Para realizar a implementação destas heurísticas, fez-se necessario a criação de duas funções, para efetuar os cálculos de raiz quadrada e módulo.<br> Referente ao funcionamento do algoritmo A* (A-estrela), por ser uma otimização do BFS,neste caso, há apenas 4 posições verificáveis possíveis - dependendo da posição em que se encontra na matriz. Juntamente com a verificação, faz-se os cálculos tanto da distância Euclidiana quanto da distância de Manhattan. Logo em seguida, enfileira o menor caminho encontrado e empilha os caminhos para um possível retorno se necessário. Portanto, ao analisar o algoritmo como um todo, percebe-se que as verificações efutadas para ambos, são relativamente idênticas, mudando apenas o cálculo efetuado pelas funções definidas no mesmo.
</p>

## Análise e Comparações

<p align = "justify"> 
 Para análise, deve ser esclarecido que o tempo de execução de um algoritmo é uma maneira bastante inadequada para fins comparativos. Uma vez que, os resultados dependem do compilador e hardware utilizado. Entretanto, para esta análise, o tempo de execução fez-se importante para comparar como a 
diferença na implementação pode implicar em um aumento de performace na resolução do problema.<br>
  Ao compilar e executar o código, aparecerá um Menu: <br> 
 <p align = "center">
   <img src = "imgs/menu.png")></img>
</p>
  Cada uma das opções de 1 à 7 irão encaminhar para suas respectivas entradas e exibirão seus resultados - caso queira encerrar, opção 0. Conforme as imagens abaixo:<br><br>
  
  <p align = "center">
   <img src = "imgs/opcao1.PNG")></img>
</p>

 <p align = "center">
   <img src = "imgs/opcao2.PNG")></img>
</p>

<p align = "center">
   <img src = "imgs/opcao3.PNG")></img>
</p>

<p align = "center">
   <img src = "imgs/opcao4.PNG")></img>
</p>

<p align = "center">
   <img src = "imgs/opcao5.PNG")></img>
</p>

<p align = "center">
   <img src = "imgs/opcao6.PNG")></img>
</p>

<p align = "center">
   <img src = "imgs/opcao7.PNG")></img>
</p>

Para conseguir valores mais adequados para comparação, foi realizado 5 execuções para cada entrada em todos os algoritmos e calculada suas médias. Dessa forma, os dados coletados - medidos pela unidade segundo(s) - foram divididos em duas tabelas, em evidência logo abaixo:
<h3 align = "center">Valores obtidos</h3>
<p align = "center">
   <img src = "imgs/media_tempos.PNG")></img>
</p>

<h3 align = "center">Comparação das médias</h3>
<p align = "center">
   <img src = "imgs/Media_Tempo_Comparativo.PNG")></img>
</p>

Após a construção e análise das duas tabelas, foi possível plotar os gráficos dos resultados obtidos na execução de cada entrada, em cada um dos algortimos testados. Dessa forma, melhora visualmente a análise comparativa de tempo. Abaixo, os gráficos estão todos nomeados com suas relativas entradas: <br>

 <p align = "center">
   <img src = "imgs/grafico_entrada1.png")></img>
</p>

 <p align = "center">
   <img src = "imgs/grafico_entrada2.png")></img>
</p>

<p align = "center">
   <img src = "imgs/grafico_entrada3.png")></img>
</p>

<p align = "center">
   <img src = "imgs/grafico_entrada4.png")></img>
</p>

<p align = "center">
   <img src = "imgs/grafico_entrada5.png")></img>
</p>

<p align = "center">
   <img src = "imgs/grafico_entrada6.png")></img>
</p>

<p align = "center">
   <img src = "imgs/grafico_entrada7.png")></img>
</p>

</p>

## Conclusão

# Compilação e Execução

Makefile realiza o procedimento de compilação e execução.

|Comando| Função|
|-----|----|
|`make clean`|Limpa tudo|
|`make r`|Executa a compilação utilizando gcc e executa o programa da pasta build após a realização da compilação.|

