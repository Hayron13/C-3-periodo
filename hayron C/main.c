#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;            // Valor armazenado no nó
    struct node *left;  // Ponteiro para o filho à esquerda
    struct node *right; // Ponteiro para o filho à direita
} Node;

// Função para inserir um nó na árvore binária de forma recursiva
void InsertNode(Node **root, int value) {
    if (*root == NULL) {
        // Aloca memória para o novo nó
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Erro ao alocar memória.\n");
            exit(1);
        }
        newNode->key = value;
        newNode->left = NULL;
        newNode->right = NULL;
        *root = newNode; // Define o novo nó como o nó atual
    } else {
        // Insere o nó na subárvore esquerda ou direita com base no valor
        if (value < (*root)->key)
            InsertNode(&(*root)->left, value);
        else if (value > (*root)->key)
            InsertNode(&(*root)->right, value);
    }
}

// Função para exibir a estrutura da árvore binária (visualização em nível)
void DisplayTree(Node *root, int level) {
    int i;

    if (root != NULL) {
        // Imprime o nível do nó atual
        for (i = 0; i < level; i++)
            printf("    |");

        printf("%d --->\n", root->key);
        level++;
        // Chama recursivamente para os filhos à esquerda e à direita
        DisplayTree(root->left, level);
        DisplayTree(root->right, level);
    } else {
        // Imprime "NULL" para representar a ausência de um nó
        for (i = 0; i < level; i++)
            printf("    |");

        printf("NULL\n");
    }
}

// Função para imprimir todos os nós folha da árvore
void PrintLeafNodes(Node *root) {
    if (root == NULL) {
        return; // Caso base: árvore vazia
    }

    // Verifica se o nó é uma folha (não tem filhos)
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->key);
    }

    // Chama recursivamente para os filhos à esquerda e à direita
    PrintLeafNodes(root->left);
    PrintLeafNodes(root->right);
}

// Função para calcular a profundidade da árvore
int CalculateDepth(Node *root) {
    if (root == NULL) {
        return 0; // Caso base: árvore vazia
    }
    
    // Calcula a profundidade das subárvores esquerda e direita
    int leftDepth = CalculateDepth(root->left);
    int rightDepth = CalculateDepth(root->right);

    // Retorna a profundidade máxima mais 1 (para o nó atual)
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

int main() {
    Node *root = NULL;

    // Inserir nós na árvore
    InsertNode(&root, 8);
    InsertNode(&root, 4);
    InsertNode(&root, 1);
    InsertNode(&root, 5);
    InsertNode(&root, 13);
    InsertNode(&root, 6);
    InsertNode(&root, 14);
    InsertNode(&root, 12);

    // Exibir a árvore
    printf("Árvore binária:\n");
    DisplayTree(root, 0);

    // Imprimir nós folha
    printf("\nNós folha: ");
    PrintLeafNodes(root);
    printf("\n");

    // Calcular e exibir a profundidade da árvore
    int depth = CalculateDepth(root);
    printf("Profundidade da árvore: %d\n", depth);

    return 0;
}
