#include<stdio.h>
#include<stdlib.h>

// Lista simplesmnete encadeada
typedef struct elemento{
    int id;
    struct elemento *prox;
}e;

void insert_element(struct elemento *lista, int id){
    
    struct elemento *novo;
    struct elemento *aux = lista; // ponteiro auxiliar
    novo = malloc (sizeof(struct elemento));
    novo->id = id;
    novo->prox = NULL;

    while (aux->prox != NULL){
        aux = aux->prox;
    }
    
    aux->prox =novo;

}

int main(){

    int idades;
    idades = malloc(50*sizeof(int));



    return 0;
    }