#include<stdio.h>
#include<stdlib.h>

// Lista simplesmnete encadeada
typedef struct Elemento{
    int id;
    struct Elemento *prox;
}e;

void insert_element(){

}

int main(){

    int idades;
    idades = malloc(50*sizeof(int));


    struct Elemento *novo;
    novo = malloc (sizeof(struct Elemento));
    novo->id = 123;
    novo->prox = NULL;

    return 0;
    }