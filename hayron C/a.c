#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore binária
typedef struct node {
    int key;            // Valor armazenado no nó
    struct node* left;  // Ponteiro para o filho à esquerda
    struct node* right; // Ponteiro para o filho à direita
} Node;

// Função para criar um novo nó com um valor específico
Node* criarNo(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->key = valor;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}

// Função para inserir um nó na árvore binária de forma recursiva
void inserirRecursivo(Node** root, int valor) {
    if (*root == NULL) {
        *root = criarNo(valor);
    } else {
        if (valor < (*root)->key) {
            inserirRecursivo(&(*root)->left, valor);
        } else if (valor > (*root)->key) {
            inserirRecursivo(&(*root)->right, valor);
        }
    }
}

// Função para encontrar e imprimir todos os nós folha da árvore
void encontrarFolhas(Node* raiz) {
    if (raiz == NULL) {
        return;
    }
    // Verifica se o nó é uma folha
    if (raiz->left == NULL && raiz->right == NULL) {
        printf("%d ", raiz->key);
    }
    // Recursivamente verifica as subárvores
    encontrarFolhas(raiz->left);
    encontrarFolhas(raiz->right);
}

// Função para exibir a estrutura da árvore binária (visualização em nível)
void mostrarArvore(Node* root, int nivel) {
    if (root != NULL) {
        // Imprime o nível do nó atual
        for (int i = 0; i < nivel; i++) {
            printf("    |");
        }
        printf("%d --->\n", root->key);
        nivel++;
        mostrarArvore(root->left, nivel);
        mostrarArvore(root->right, nivel);
    } else {
        // Imprime um marcador para nós nulos
        for (int i = 0; i < nivel; i++) {
            printf("    |");
        }
        printf("NULL\n");
    }
}

int main() {
    // Criando uma árvore binária inicial com nós predefinidos
    Node* raiz = criarNo(1);
    raiz->left = criarNo(2);
    raiz->right = criarNo(3);
    raiz->left->left = criarNo(4);
    raiz->left->right = criarNo(5);
    raiz->right->right = criarNo(6);

    // Encontrar e imprimir nós folha da árvore inicial
    printf("Nós folha da árvore inicial: ");
    encontrarFolhas(raiz);
    printf("\n");

    // Criando uma nova árvore binária dinamicamente
    Node* root = NULL;
    inserirRecursivo(&root, 8);
    inserirRecursivo(&root, 4);
    inserirRecursivo(&root, 1);
    inserirRecursivo(&root, 5);
    inserirRecursivo(&root, 13);
    inserirRecursivo(&root, 6);
    inserirRecursivo(&root, 14);

    // Encontrar e imprimir nós folha da árvore criada dinamicamente
    printf("Nós folha da árvore criada dinamicamente: ");
    encontrarFolhas(root);
    printf("\n");

    // Exibir a estrutura da árvore criada dinamicamente
    printf("Estrutura da árvore criada dinamicamente:\n");
    mostrarArvore(root, 0);

    // Liberação de memória não foi implementada, o que seria importante em um código real

    return 0;
}
