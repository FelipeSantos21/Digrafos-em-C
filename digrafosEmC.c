/*
    TAD do Digrafo
    Digrafo: ponteiro de arestas

    -criaAresta (Ponteiro para o digrafo, vertice 1, vertice 2, peso da aresta): Cria a aresta entre o vertice 1 e 2 com o peso especificado.
    -removeAresta (Ponteiro para o digrafo, vertice 1, vertice 2): Remove a aresta entre o vertice 1 e 2.
    -mostraArestas (Ponteiro para o digrafo): Lista as arestas.
*/

#include <stdio.h>
#include <malloc.h>

#define maxVertices 50

typedef struct _aresta {
    int vertice;
    int peso;
    struct _aresta *prox;
} *aresta;

void criaAresta (aresta* pointDigrafo, int vertice1, int vertice2, int peso) {
    
    aresta aux1, aux2;
    aux1 = aux2 = pointDigrafo[vertice1];
    
    aresta novaAresta = (aresta) malloc(sizeof(struct _aresta));
    novaAresta->vertice = vertice2;
    novaAresta->peso = peso;
    novaAresta->prox = NULL;

    if (pointDigrafo[vertice1] == NULL){		//Insercao na lista partindo de v1 vazia
		pointDigrafo[vertice1] = novaAresta;
		system("cls");
		printf("Aresta %d->%d criada com sucesso.\n\n", vertice1, vertice2);
		return;
	}
	else if(pointDigrafo[vertice1]->vertice == vertice2){			//Caso a nova aresta seja a primeira da lista
		system("cls");
		printf("Aresta %d->%d ja existente.\n\n", vertice1, vertice2);
		return;
	}
	else if(pointDigrafo[vertice1]->vertice > vertice2){		//Insercao no inicio da lista partindo de v1 
		novaAresta->prox = pointDigrafo[vertice1];
		pointDigrafo[vertice1] = novaAresta;
		system("cls");
		printf("Aresta %d->%d criada com sucesso.\n\n", vertice1, vertice2);
		return;
	}
	else{
		while(aux1 != NULL){		//Percorre a lista com ponteiro atrasado
			if(aux1->vertice == vertice2){			//Caso a nova aresta esteja em algum lugar da lista
				system("cls");
				printf("Aresta %d->%d ja existente.\n\n", vertice1, vertice2);
				return;
			}
			else if(aux1->vertice > vertice2){			//Insercao no meio da lista
				novaAresta->prox = aux1;
				aux2->prox = novaAresta;
				system("cls");
				printf("Aresta %d->%d criada com sucesso.\n\n", vertice1, vertice2);
				return;
			}
			aux2 = aux1;
			aux1 = aux2->prox;
		}
		aux2->prox = novaAresta;		//Insercao no final da lista
		system("cls");
		printf("Aresta %d->%d criada com sucesso.\n\n", vertice1, vertice2);
	}
}

void removeAresta (aresta* pointDigrafo, int vertice1, int vertice2) {
    
	aresta aux1, aux2;
    aux1 = aux2 = pointDigrafo[vertice1];
	
	if (pointDigrafo[vertice1] == NULL){
		system("cls");
		printf("Aresta %d->%d nao encontrada!\n\n", vertice1, vertice2);
	}
	else if(pointDigrafo[vertice1]->vertice == vertice2){		//Remove a chave no inicio da lista
		pointDigrafo[vertice1] = aux1->prox;
		free(aux1);
		system("cls");
        printf("Aresta %d->%d removida com sucesso!\n\n", vertice1, vertice2);
		return;
	}
	else{
		while(aux1 != NULL){		//Percorre a lista com ponteiro atrasado
			if(aux1->vertice == vertice2){		//Remove a chave do meio ou final da lista
				aux2->prox = aux1->prox;
				free(aux1);
				system("cls");
                printf("Aresta %d->%d removida com sucesso!\n\n", vertice1, vertice2);
				return;
			}
			aux2 = aux1;
			aux1 = aux2->prox;
		}
		system("cls");
        printf("Aresta %d->%d nao encontrada!\n\n", vertice1, vertice2);
	}
}

void mostraArestas (aresta* pointDigrafo) {
    int i;
    aresta aux;

    system("cls");

    for(i = 0; i<maxVertices; i++){
        if(pointDigrafo[i] != NULL){
            printf("Aresta de [%d] para [%d] (peso %d)",i ,pointDigrafo[i]->vertice, pointDigrafo[i]->peso);
            aux = pointDigrafo[i]->prox;
            while(aux != NULL){
                printf(", [%d] (peso %d)", aux->vertice, aux->peso);
                aux = aux->prox;
            }
            printf("\n");
        }
    	else printf("\n");
	}
}

void printMenu(){
	printf("Escolha uma das opcoes:\n    1 - Criar aresta\n    2 - Remover aresta\n    3 - Mostrar arestas existentes\n    4 - Sair\n");
}

int main(int argc, const char * argv[]) {
    int i, opcao, v1, v2, p;
    aresta *pointDigrafo[maxVertices];

    for(i = 0; i<maxVertices; i++){
        pointDigrafo[i] = NULL;
    }

    do{
        printMenu();
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite o primeiro vertice da aresta: ");
                scanf("%d", &v1);
				printf("Digite o segundo vertice da aresta: ");
				scanf("%d", &v2);
				while(v1==v2){
					printf("O segundo vertice nao pode ser o mesmo que o primeiro, digite outro valor: ");
					scanf("%d", &v2);
				}
                printf("Digite o peso da aresta: ");
                scanf("%d", &p);
                criaAresta(&pointDigrafo, v1, v2, p);
                break;
            case 2:
                printf("Digite o primeiro vertice da aresta: ");
                scanf("%d", &v1);
                printf("Digite o segundo vertice da aresta: ");
                scanf("%d", &v2);
				while(v1==v2){
					printf("O segundo vertice nao pode ser o mesmo que o primeiro, digite outro valor: ");
					scanf("%d", &v2);
				}
                removeAresta(&pointDigrafo, v1, v2);
                break;
            case 3:
                mostraArestas(&pointDigrafo);
                break;
        }
	}while(opcao != 4);
}