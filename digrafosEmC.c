/*
    TAD do Digrafo
    Digrafo: ponteiro de arestas

    -geraAresta (Ponteiro para o digrafo, vertice 1, vertice 2, peso da aresta): Gera a aresta entre o vertice 1 e 2 com o peso especificado.
    -removeAresta (Ponteiro para o digrafo, vertice 1, vertice 2): Remove a aresta entre o vertice 1 e 2.
    -mostraArestas (Ponteiro para o digrafo): Lista as arestas.
*/
#include<stdio.h>;
#include<malloc>;

#define maxVertices 50

typedef struct _aresta {
    int vertice;
    int peso;
    struct _aresta *prox;
} *aresta;

void geraAresta (aresta* pointDigrafo, int vertice1, int vertice2, int peso) {
    aresta novaAresta = (aresta) malloc(syzeof(struct _aresta));
    novaAresta->peso = peso;
    novaAresta->vertice = vertice2;
    novaAresta->prox = NULL;

    bool 

    aresta aux = pointDigrafo[vertice1];
    while (aux) {

        aux = aux->prox; // Passa para a proxima aresta da lista.
    }
    
}

void removeAresta (aresta* pointDigrafo, int vertice1, int vertice2) {

}

void mostraArestas (aresta* pointDigrafo) {

}

int main () {

    return 0;
}