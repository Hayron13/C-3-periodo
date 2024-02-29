#include<stdio.h>

// Conceito de ponteiro
int main(){
    int *p1;
    int idade =34;
    char *p2;
    float *p3;

    p1 = &idade;
    printf("%p\n", p1);

    return 0;
    }