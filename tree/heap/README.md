# Heap

A estrutura de dados Heap (binário) é um objeto arranjo/array que pode ser vista como uma árvore binária quase completa, onde cada elemento do array corresponde a um nó da árvore. Por ser uma árvore “quase completa” todos os níveis estarão preenchidos, exceto o último, que poderá está ou não preenchido, sendo esse preenchimento feito da esquerda para direita sem lacunas.
	
A raiz da árvore fica no índice *i = 0*, ou melhor, *array[0]*. Dado um determinado índice *i* de um nó, é possível calcular facilmente o índice de seu pai, do filho à esquerda e do filho à direita utilizando as fórmulas:
- *PARENT(i)* = (i – 1) / 2
- *CHILD_LEFT(i)* = 2 * i + 1
- *CHILD_RIGHT(i)* = 2 * i + 2

Existem dois tipos de Heaps Binários: 
- Heaps Máximo (Max-Heap), é aquele onde todos os nós são “menores” que seus respectivos pais. Resumidamente representado como, *ARRAY[PARENT(i)] >= ARRAY[I]*, exceto para o nó *i* raiz.

- Heap Mínimo (Min-Heap), é aquele onde todos os nós são “maiores” que seus respectivos pais. Resumidamente representado como, *ARRAY[PARENT(i)] <= ARRAY[I]*, exceto para o nó *i* raiz.

</br>

## Construção de um Heap

Legenda
  - Em Roxo: posíção atual de *i* (elemento atual);
  - Em Vermelho: menor elemento entre *i*,*CHILD_LEFT(i)* e *CHILD_RIGHT(i)* - subárvore de *i*;
  - Gradiente: o elemento atual já é o menor elemento da subárvore.

### Heapify

O Heapify é o procedimento pelo qual se mantêm a propriedade de Heap. Esse procedimento tem como entrada o arranjo e um índice *i*. Quando chamado em um procedimento de Min-Heapfify, ou seja, em um Heap Mínimo, é verificado qual dos dois filhos de *i* – *CHILD_LEFT(i)* e *CHILD_RIGHT(i)* – é o menor, e caso ele seja também menor que seu pai ele “flutua para cima”, trocando de posição com seu pai. Esse processo é repetido até que a subárvore de *i* obedeça à propriedade Heap.

### Construção do Heap

Podemos usar o procedimento de Heapify de baixo para cima para converter todo o arranjo em Heap.
Dado um arranjo de tamanho *n*, os elementos compreendidos no intervalo [(n / 2 + 1) ... n] são nós folha da árvore, por isso podemos o inciar o Heapify com *i = PARENT(n)*. Assim, já de início, a subárvore de *i* terá pelo menos um elemento. Após cada processo de Heapify decrescemos uma unidade de *i*, com *i <= i – 1* até que *i = -1*, delimitando o final da execução.

<center>
  <figure> 
    <img src="../.images/heap0.png" alt="Construção da Heap">
    <figcaption>
      <i>Construção do Heap.</i>
    </figcaption>
  </figure>
</center>

</br>

### Inserção em um Heap

A inserção é bem semelhante ao processo de construção, com a diferença de não ter um loop. O elemento inserido será adicionado no final do arranjo, ou seja, no índice *n + 1*, ou melhor, *array[n + 1]*, onde *n* é o tamanho do arranjo antes da inserção. Após isso será chamado o Heapify de baixo para cima  iniciando no índice *i = PARENT(n + 1)*.

<center>
  <figure>
    <img src="../.images/heap1.png" alt="Inserção de um novo item na heap.">
    <figcaption>
      <i>Inserção de um novo item com o valor "-7" no Heap.</i>
    </figcaption>
  </figure>
</center>

</br>

### Remoção em um Heap

Em um heap o processo de remoção sempre retirará o elemento no topo da árvore, no caso de um Min-Heap removerá o menor elemento. Pela propriedade Heap esse elemento estará sempre no índice *i = 0*, ou melhor, *array[0]*. Após a remoção o que deve ser feito é transferir o último elemento para o topo da árvore, ou seja, *array[0] <= array[n]*, e executar o processo de Heapify de cima para baixo iniciando com o índice *i = 0*.

<center>
  <figure>
    <img src="../.images/heap3.png" alt="Diagrama de operações primitivas em uma pilha estática">
    <figcaption>
      <i>Remoção de um item do Heap.</i>
    </figcaption>
  </figure>
</center>

### Complexidade

Visto que um Heap é baseado em uma árvore binária completa, sua altura é *(lg n)*, com *n* representando o tamanho do conjunto. Com isso, as operações básicas de um heap são executadas no máximo em tempo proporcional à altura da árvore, assim demorando um tempo *O(lg n)*.

- Heapfy: *O(lg n)*;
- Build-Heap: *O(n)*;
- Insert: *O(lg n)*;
- Remove: *O(lg n)*;
- Peek: *O(1)*;

## Aplicações
- HeapSort;
- Fila de Prioridade (Priority Queue);

## Referências
- Cormen, H. T.; Leiserson, C. E.; Rivest, R. L.; Stein, C. Algoritmos: Teoria e Prática. 3ª Edição.
- [Heap, in Wikipedia.](https://pt.wikipedia.org/wiki/Heap)