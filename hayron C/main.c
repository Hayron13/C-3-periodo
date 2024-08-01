#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int key;
    struct no *left;
    struct no *right;
} node;

void RecursiveInsert(node **root, int valor) {
    node *novo = (node *)malloc(sizeof(node));
    novo->key = valor;
    novo->left = NULL;
    novo->right = NULL;

    if (*root != NULL) {
        if (valor < (*root)->key)
            RecursiveInsert(&(*root)->left, valor);
        else if (valor > (*root)->key)
            RecursiveInsert(&(*root)->right, valor);
    } else {
        *root = novo;
    }
}


void ShowTree(node *root, int level) {
    int i;

    if (root != NULL) {
        for (i = 0; i < level; i++)
            printf("    |");

        printf("%d --->", root->key);
        level++;
        printf("\n");
        ShowTree(root->left, level);
        printf("\n");
        ShowTree(root->right, level);
    } else {
        for (i = 0; i < level; i++)
            printf("    |");

        printf("NULL");
    }
}

void PrintLeafNodes(node *root) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->key);
    }

    PrintLeafNodes(root->left);
    PrintLeafNodes(root->right);
}

int main() {
    node *root = NULL;

    RecursiveInsert(&root, 8);
    RecursiveInsert(&root, 4);
    RecursiveInsert(&root, 1);
    RecursiveInsert(&root, 5);
    RecursiveInsert(&root, 13);
    RecursiveInsert(&root, 6);
    RecursiveInsert(&root, 14);
    RecursiveInsert(&root, 12);

    printf("Árvore binária:\n");
    ShowTree(root, 0);

    
    printf("\nNós folha: ");
    PrintLeafNodes(root);
    printf("\n");

    return 0;
}
