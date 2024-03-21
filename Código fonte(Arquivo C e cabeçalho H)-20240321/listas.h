#include<stdio.h>
#include<stdlib.h>

//LISTA SIMPLESMENTE ENCADEADA
typedef struct elemento{
    int id;
    struct elemento *prox;
}Elemento;

void insere_elemento(Elemento **lista, int id){

    Elemento *novo;
    Elemento *aux; // Ponteiro auxiliar.
    novo = (Elemento *) malloc(sizeof(Elemento));

    novo->id = id;
    novo->prox = NULL;

    if (*lista != NULL){
        aux = *lista;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }else{
        *lista = novo;
    }
}

void mostrar_lista(Elemento *lista){
    Elemento *aux = lista;

    if(lista == NULL){
        printf("\n:: EMPTY LIST ::\n");
    }
    else{
        printf(":: LIST BEGIN ::\n");
        do{
            printf("ID: %d.\n",aux->id);
            aux = aux->prox;
        }while(aux != NULL);
        printf(":: LIST END ::\n\n");
    }
}

void remove_elemento(Elemento **lista,int id){
    Elemento *aux = *lista;
    Elemento *anterior;


    //TESTANDO O PRIMEIRO
    if(aux->id == id){
        *lista = aux->prox;
    }else {
        anterior = *lista;
        aux = aux->prox;
        while(aux != NULL){
            if(aux->id == id){
                anterior->prox = aux->prox;
                break;
            }else{
                anterior = aux;
                aux = aux->prox;
            }
        }

    }
}

void insere_ordenado(Elemento **lista, int id){

    Elemento *novo;
    novo = (Elemento *) malloc(sizeof(Elemento));
    novo->id = id;
    novo->prox = NULL;

    Elemento *aux = *lista;
    Elemento *anterior;
    int flag = 0;

    if(aux == NULL){
        *lista = novo;
    }else{
        //TESTANDO O PRIMEIRO ELEMENTO
        if(aux->id > id) {
            novo->prox = aux;
            *lista = novo;
        }else{
            anterior = aux;
            aux = aux->prox;
            while(aux != NULL){
                if(aux->id > id){
                    anterior->prox = novo;
                    novo->prox = aux;
                    flag = 1;
                    break;
                }else{
                    anterior = aux;
                    aux = aux->prox;
                }
            }
            if(flag == 0){
                anterior->prox = novo;
            }
        }
    }
}
