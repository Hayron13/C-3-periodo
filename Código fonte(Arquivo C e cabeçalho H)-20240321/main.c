#include<stdio.h>
#include "listas.h"

void menu(){
    printf("\n:: MENU ::\n\n");
    printf(":: 1 - Inserir ordenado\n");
    printf(":: 2 - Mostrar Lista.\n");
    printf(":: 3 - Remover elemento.\n");
    printf(":: 5 - ->SAIR\n\n");
}

int main(){
    Elemento *lista = NULL;
    int option;
    int id_novo;
    
    do{
        menu();
        scanf("%d",&option);

        switch (option){
        case 1:
            printf("Digite o id do novo elemento:\n");
            scanf("%d",&id_novo);
            insere_ordenado(&lista, id_novo);
            break;
        case 2:
            mostrar_lista(lista);
            break;
        case 3:
            printf("Digite o id do elemento a ser apagado:\n");
            scanf("%d",&id_novo);
            remove_elemento(&lista,id_novo);
            break;
        case 5:
            return 0;
        default:
            printf(":: INVALID OPTION ::");
            break;
        }        
    }while(option != 5);

    return 0;
}