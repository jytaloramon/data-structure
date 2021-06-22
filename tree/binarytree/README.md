# Binary Tree (Árvore Binária)

Uma árvore binária é um conjunto finito de elementos particionados em três subconjuntos disjuntos, quando não vazio. Cada elemento em uma árvore é chamado de nó, o primeiro subconjunto contem um único elemento, denominado nó raiz da árvore. Os dois outros subconjuntos são em si uma árvore binária, logo denominado subárvore da esquerda ou da direita a partir de um nó referência.

Além disso, se *A* é um elemento da árvore e *B* é a raiz de uma subárvore direita/esquerda de *A*, então dizemos que *A* é o pai de *B* e que *B* é o filho da direita/esquerda de *A*.

Uma árvore binária tem em sua propriedade matemática básica o pressuposto de: 
Sendo *w* uma chave(valor) e seja *x* outra chave, se *x* <= *w*, então *x* estará na subárvore da esquerda de *w*. Caso *x* => *w*, então *x* estará na subárvore da direita de *w*.

## Definições Extras

- Um nó que não possui filho é chamado de **Nó Folha**.

- Se todos os nós não folha tiverem tiver a subárvore da esquerda e direita não vazia, a árvore será considerada uma **Árvore Estritamente Binária**. Uma árvore com essa característica e com *n* folha terá sempre *2n - 1* nós. 

- Sendo o nó raiz o **Nível** 0, a distância entre ele e um nó *G* qualquer denomina o **Nível** em que *G* está.

- A **Profundidade** de uma árvore binária é equivalente a nível máximo de qualquer folha da árvore. Em outras palavras, a maior distância entre o nó raiz e a um nó folhar qualquer.

- Uma **Árvore Binária Completa** de profundidade *d* é uma árvore estritamente binária em que todos os nós folha estão no nível *d*.

- Se uma árvore binária contiver *m* nós no nível *l*, estão ela conterá no máximo ***2m* no nível *l + 1***.

- O **Número Total de Nós** em uma árvore binária completa é sempre ***(2^(d + 1)) - 1***, onde *d* é a profundidade da árvore menos 1 (*-1*). Essa fórmula também pode ser usada para saber quantos nós existe no máximo em um nível *d* qualquer. De forma semelhante, para calcular a quantidade de nós folhar é usado a formular ***2^t***, onde *t* é o nível que estão esses nós.

- Uma árvore binária de profundidade *d* será uma **Árvore Binária Quase Completa** se:
  1. Cada folha estiver no nível *d* ou *d - 1*
  2. Para cada nó *G* na árvore com um descendente direto no nível *d*, todos os descendentes esquerdos de *G* que forem folhas estivem também no nível *d*.


## Operações em uma Árvore Binária 

### Inserção de Nó

O processo de inserção em uma árvore é bem simples, se não houver elemento na árvore o novo valor é inserido na raiz. Caso haja:

0. Sendo *P* o novo valor a ser inserido. 
1. Iniciamos na raiz da árvore, o elemento atual será *G*.
2. *P* é comparado com o *G*.
3. Se *P* for menor ou igual a *G*, o "novo valor de *G*" será o filho esquerdo do *G* atual, caso não, o "novo valor *G*" será o filho direito do *G* atual.
4. Repete o processo 2 e 3 até *G* ser nulo, delimitando o ponto em que deve-se inserir *P*.

<center>
  <figure> 
    <img src="../.images/tree0.png" alt="Inserção em uma árvore binária.">
    <figcaption>
      <i>Figura 1: Inserção em uma árvore binária.</i>
    </figcaption>
  </figure>
</center>

</br>

### Remoção de Nó

Antes de entrarmos na explicação de fato vamos imagine um cenário: temos uma lista de valores que respeita a seguinte propriedade: (1) existe um elemento, denominado pivô, que divide a lista em duas partes; (2) todos os elementos que estão à esquerda desse pivô são menores que ele e todos que estão à direita são maiores que ele. Figura 2a.

Se removermos esse elemento pivô (15), qual deverá ser o valor(es) que podemos colocar no lugar para não perdemos essa propriedade. Figuras 2b, 2c e 2d.

Respondeu certo quem falou 8 ou 23. Vamos entender o porquê disso. Para isso ordenaremos a lista (Figura 2e). Agora se olharmos bem veremos que 8 e o 23 são os elementos mais próximos do 15. Logo, se removêssemos o pivô e delocassem todos elementos do lado esquerdo/direito em direção ao centro não haveria diferença na ordem dos elemento. Portanto, podemos colocar nesse espaço tanto o maior elemento da esquerda quanto o menor elemento da direita. Posto isso podemos prosseguir com a explicação. 

<center>
  <figure> 
    <img src="../.images/tree2.png" alt="Remoção em uma árvore binária.">
    <figcaption>
      <i>Figura 2: Lista com elemento pivô.</i>
    </figcaption>
  </figure>
</center>

</br>

A estratégia para remoção de um nó *Z* em uma árvore binária *T* (Figura 3a) passa primeiro por encontrar *Z*, caso *Z* exista iremos checar três casos básicos.

- Se *Z* não possuir filhos, nesse caso apenas remover *Z*. Figuras 3f, 3g, 3h e 3i.

- O nó *Z* possui apenas um filho, Figuras 3b. Nesse caso, esse filho irá ocupar a posição de *Z*, Figura 3c e 3d.

- Chegamos no caso mais complicado, quando *Z* possui dois filhos. Nessa situação *Z* será substituído por um de seus descendentes, chamaremos esse elemento de *Y*. Nesse caso *Y* será o filho mais à esquerda da subárvore direita (item azul na figura) de *Z*, Figura de 3i a 3l. Pode acontece de *Y* ter um filho, necessariamente ele está à direita de *Y*, nesse caso ele tomará o lugar atual de *Y*. Como mostrado cenário hipotético anteriormente, *Y* também poderia ser o elemento mais à direita da subárvore esquerda de *Z*.

<center>
  <figure> 
    <img src="../.images/tree1.png" alt="Remoção em uma árvore binária.">
    <figcaption>
      <i>Figura 3: Remoção em uma árvore binária.</i>
    </figcaption>
  </figure>
</center>

</br>

### Complexidade

Visto que um Heap é baseado em uma árvore binária completa, sua altura é *(lg n)*, com *n* representando o tamanho do conjunto. Com isso, as operações básicas de um heap são executadas no máximo em tempo proporcional à altura da árvore, assim demorando um tempo *O(lg n)*.

- Insert: *O(lg n)*;
- Remove: *O(lg n)*;

## Aplicações
- Encontrar as repetições de uma determinada lista.

## Referências
- Tenenbaum, A. A.; Langsam, Y.; Augenstein, M. J. Estruturas de Dados Usando C.
- Cormen, H. T.; Leiserson, C. E.; Rivest, R. L.; Stein, C. Algoritmos: Teoria e Prática. 3ª Edição.

[incompleto]

------
