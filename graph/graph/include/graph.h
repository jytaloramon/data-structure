/**
 * @author Ytalo Ramon
 * @date   09/08/2021
 */

#include "../../../list/include/static_list.h"
#include "stdlib.h"

typedef struct _Vertex Vertex;

typedef struct _Edge Egde;

typedef struct _Graph Graph;

struct _Graph {
    struct _List *items;
};

Graph *graph_new(int size) {

    Graph *graph = (Graph *)malloc(sizeof(Graph));

    if (!graph)
        return NULL;

    graph->items = list_new(size);

    return graph;
}

Egde *graph_new_edge(Vertex *v1, Vertex *v2){

    if (!v1 || !v2)
        return NULL;

    

}