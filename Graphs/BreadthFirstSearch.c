/**
 * Na teoria dos grafos, busca em largura (ou busca em amplitude, também conhecido em inglês por Breadth-First Search - BFS) 
 *      é um algoritmo de busca em grafos utilizado para realizar uma busca ou travessia num grafo e estrutura de dados do tipo árvore. 
 * Intuitivamente, você começa pelo vértice raiz e explora todos os vértices vizinhos. Então, para cada um desses vértices mais próximos,
 *      exploramos os seus vértices vizinhos inexplorados e assim por diante, até que ele encontre o alvo da busca.
 * Complexidade: pior - O(nº Vertices + nº Arestas), melhor - O(1)
 * Fonte.: Wikipédia
 */

#include "stdio.h"
#include "stdlib.h"

#define MAX 10

typedef struct _vertex{
    int id,
        visited, 
        indexNeighbor;
    struct _vertex *vertexNeighbors[MAX];
} Vertex;

typedef struct _element{
    struct _vertex *vertex;
    struct _element *proxEl;
} Element;

typedef struct _queue{
    struct _element *front, **last;
} Queue;

void printVertex(Vertex *vertex);

void printQueue(Queue *queue);

void addWayBiDirectional(Vertex *vertex1, Vertex *vertex2);

Element *createEl(Vertex *vertex);

void enqueue(Queue *queue, Vertex *vertex);

Element *dequeue(Queue *queue);

int queueIsEmpty(Queue *queue);

int main(int argc, char const *argv[]){
    
    Vertex vertex[MAX], *vertexAux;
    Queue queue = { NULL, &queue.front };

    // Inicializando valores dos vertices
    for (int i = 0; i < MAX; i++){
        vertex[i].id = i;
        vertex[i].visited = vertex[i].indexNeighbor = 0;
    }

    // Adicionando caminhos bi-direcionais entre os vertices a <-para-> b
    addWayBiDirectional(&vertex[0], &vertex[5]);
    addWayBiDirectional(&vertex[5], &vertex[4]);
    addWayBiDirectional(&vertex[8], &vertex[2]);
    addWayBiDirectional(&vertex[0], &vertex[9]);
    addWayBiDirectional(&vertex[0], &vertex[3]);
    addWayBiDirectional(&vertex[2], &vertex[3]);
    addWayBiDirectional(&vertex[5], &vertex[0]);
    addWayBiDirectional(&vertex[3], &vertex[7]);
    addWayBiDirectional(&vertex[8], &vertex[1]);
    addWayBiDirectional(&vertex[1], &vertex[9]);
    addWayBiDirectional(&vertex[6], &vertex[5]);
    addWayBiDirectional(&vertex[1], &vertex[6]);

    printf("Estado dos vertices\n\n");
    for (int i = 0; i < MAX; i++)
        printVertex(&vertex[i]);
    
    // Vertice de início do percusso (BFS)
    vertexAux = &vertex[0];
    vertexAux->visited = 1;
    printf("Print usando \"Busca em largura(BFS)\" a parti do id: %d, ordem de visita.\n", vertexAux->id);

    // Percorrer(run)
    while (vertexAux){
        printf("    Id: %d\n", vertexAux->id);

        // Para cada vertice será percorrido todos os vizinhos
        for (int i = 0; i < vertexAux->indexNeighbor; i++){
            
            // Se o vizinho ainda não tiver sido adicionando a fila adicionaremos, ativando a flag dele como visitado
            if(!vertexAux->vertexNeighbors[i]->visited){
                vertexAux->vertexNeighbors[i]->visited = 1;
                enqueue(&queue, vertexAux->vertexNeighbors[i]);
            }
        }

        // desenfileiraando os elementos
        Element *el = dequeue(&queue);
        vertexAux = el ? el->vertex : NULL;
    }

    return 0;
}

void printVertex(Vertex *vertex){
    printf("Id atual: %d\n      N.Vizinho: %d ===>", vertex->id, vertex->indexNeighbor);
    
    for (int i = 0; i < vertex->indexNeighbor; i++)
        printf(" %d", vertex->vertexNeighbors[i]->id);

    printf("\n\n");   
}

void printQueue(Queue *queue){
    printf("Fila ===>");

    Element *el = queue->front;

    while (el){
        printf(" %d", el->vertex->id);
        el = el->proxEl;
    }

    printf("\n\n");
}

void addWayBiDirectional(Vertex *vertex1, Vertex *vertex2){
    int *indexNeigh1 = &vertex1->indexNeighbor,
        *indexNeigh2 = &vertex2->indexNeighbor;

    if(*indexNeigh1 >= MAX || *indexNeigh2 >= MAX){
        printf("Nao dar para criar caminho, limite excedido");

        return;
    }        

    vertex1->vertexNeighbors[(*indexNeigh1)++] = vertex2;
    vertex2->vertexNeighbors[(*indexNeigh2)++] = vertex1;
}

Element *createEl(Vertex *vertex){
    Element *el = malloc(sizeof(Element));
    el->vertex = vertex;
    el->proxEl = NULL;

    return el;
}

void enqueue(Queue *queue, Vertex *vertex){
    Element *el = createEl(vertex);

    *(queue->last) = el;
    queue->last = &el->proxEl;
}

Element *dequeue(Queue *queue){

    if(queueIsEmpty(queue))
        return NULL;
    
    Element *el = queue->front;
    queue->front = el->proxEl;

    if (!queue->front)
        queue->last = &queue->front;

    return el;
}

int queueIsEmpty(Queue *queue){
    return queue->front == NULL;
}