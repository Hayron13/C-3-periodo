#include <stdio.h>
#include <stdlib.h>

int main() {
    int idade1, idade2;

    printf("idade 1: ");
    scanf("%d", &idade1);

    printf("idade 2: ");
    scanf("%d", &idade2);

    if (idade1 > idade2) {
        printf("Maior que %d\n", idade2);
    } else if (idade1 < idade2) {
        printf("Menor que %d\n", idade1);
    } else {
        printf("Idades iguais\n");
    }

    return 0;
}
