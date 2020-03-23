/**
 * Binary Tree, ou Árvore binária, é uma estrutura de dados onde cada nó tem no máximo dois filhor: um esquedo e um direito.
 * O nó raiz(root) é o único que não é filho de nenhum outro.
 * Para todo nó existente seu filho da esquerda terá sua chave/valor menor que seu pai e, o filho a direita terá um valor maior que seu pai.
 * Ref.: ime.usp.br
 * */

#include "stdio.h"
#include "stdlib.h"

typedef struct _tree{
    struct _node *nodeRoot;
} Tree;

typedef struct _node{
    int value;
    struct _node *left, *right;
} Node;

Node* createNode(int value);

int empty(Node *node);

void inserir(Node **nodeActual, int value);

Node* search(Node *nodeActual, int value);

void inorder(Node *nodeActual); // (left, raiz, right)

void preorder(Node *nodeActual); // (raiz, left, right)

void postorder(Node *nodeActual); // (left, right, raiz)

int main(int argc, char const *argv[]){

    Tree tree;
    tree.nodeRoot = NULL;

    Node *nodeAux;
    int opt, value;

    do {
        printf("[1] Inserir\n[2] Procurar\n[3] em-ordem\n[4] Pre-ordem\n[5] Pos-ordem\n[Q] Exit\nDigite: ");
        scanf("%d", &opt);

        switch (opt){
            case 1:
                printf("Inserir value: ");
                scanf("%d", &value);

                inserir(&tree.nodeRoot, value);
                break;
        
            case 2:
                printf("Valor procurado: ");
                scanf("%d", &value);

                nodeAux = search(tree.nodeRoot, value);
                if (nodeAux != NULL)
                   printf("Valor: %d\n", nodeAux->value);
                else
                    printf("Valor nao encontrado!\n");
                
                break;

            case 3:
                inorder(tree.nodeRoot);
                printf("\n");
                break;
            
            case 4:
                preorder(tree.nodeRoot);
                printf("\n");
                break;

            case 5:
                postorder(tree.nodeRoot);
                printf("\n");
                break;

            default:
                exit(0);

            getchar();
        }

        printf("\n"); 
    } while (1);
    
    return 0;
}

Node* createNode(int value){
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int empty(Node *node){
    return node == NULL;
}

void inserir(Node **nodeActual, int value){
    if (empty(*nodeActual)){
        *nodeActual = createNode(value);
        return;
    }
    
    if(value == (*nodeActual)->value) 
        return;
    
    value < (*nodeActual)->value ? inserir(&(*nodeActual)->left, value) : inserir(&(*nodeActual)->right, value);
}

Node* search(Node *nodeActual, int value){
    if(empty(nodeActual))
        return NULL;
    
    if(nodeActual->value == value)
        return nodeActual;
    
    return value < nodeActual->value ? search(nodeActual->left, value) : search(nodeActual->right, value);
}

void inorder(Node *nodeActual){
    if(empty(nodeActual))
        return;
    
    inorder(nodeActual->left);
    printf("%d ", nodeActual->value);
    inorder(nodeActual->right);
}

void preorder(Node *nodeActual){
    if(empty(nodeActual))
        return;
    
    printf("%d ", nodeActual->value);
    preorder(nodeActual->left);
    preorder(nodeActual->right);
}

void postorder(Node *nodeActual){
    if(empty(nodeActual))
        return;
    
    postorder(nodeActual->left);
    postorder(nodeActual->right);
    printf("%d ", nodeActual->value);
}