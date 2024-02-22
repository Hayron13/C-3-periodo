#include<stdio.h> //Standard INPUT/OUTPUT (stdIO).
#include<string.h>

// INTEIRO - int and its modifiers (short, long,...)
// REAL - float and double.
// CHAR - characters from ASCII table.
// Tipos Abstratos de Dados (TAD)

typedef struct Pessoa{
    int id;
    char nome[20];
}p;

//Listas sequenciais possibilitam
//algoritmos iterativos.

int insere_elemento(struct Pessoa *l,int tamanho, int id, char *nome){

    if(tamanho >= 10){
        printf(":: OVERFLOW ::\n");
        return tamanho;
    }

    l[tamanho].id = id;
    strcpy(l[tamanho].nome,nome);

    tamanho++;
    return tamanho;

}

void MostrarElemento(struct Pessoa *l,int n){
    printf("O id do elemento %d é %d.\n",n,l[n].id);
    printf("O nome do elemento %d é %s.\n",n,l[n].nome);
}

void Mostrarlista(struct Pessoa *l, int tamanho)
{
    int i;
    printf(":: EXIBINDO LISTA ::\n\n");
    for(i=0;i < tamanho; i++){
        printf("ID: %d || Nome: \n",l[i].id,l[i].nome);
    }

    printf("\n:: FIM DA LISTA ::\n");
}


int main(){
    
    //LISTA SEQUENCIAL ESTÁTICA
    struct Pessoa lista[10];
    int tamanho = 0;

    //EXERCÍCIO
    //insere_elemento();
    tamanho = insere_elemento(&lista,tamanho,123,"Janio");
    tamanho = insere_elemento(&lista,tamanho,456,"Cauã");
    MostrarElemento(&lista, 1);
    printf("O tamanho atual da lista é %d\n.",tamanho);

    //remove_elemento();

   int op = 0;{
        printf("\nMENU\n");
        printf("\nInserir user\n");
        printf("\nConsultar user pelo id\n");
        printf("\nRemover user pelo id\n");
        printf("\nMostrar lista\n");
        printf("\nSair\n");
   }    

    return 0;
}