/* Solução para o problema 7. */
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
    struct node *father;
} node;

typedef struct tree
{
    node *root;
} tree;

node* createNode(int);
tree* create(void);
void insert(tree*, node*);
int search(tree*, int);

int main(void)
{
    int nodesAmount, value;
    scanf("%d", &nodesAmount);

    tree *tr = create();
    for (int i = 0; i < nodesAmount; i++) {
        scanf("%d", &value);
        insert(tr, createNode(value));
    }

    return 0;
}

node* createNode(int key)
{
    node *n = (node*)malloc(sizeof(node));
    if (n != NULL) {
        n->key = key;
        n->father = NULL;
        n->left = NULL;
        n->right = NULL;
    }
    return n;
}

tree* create(void)
{
    tree *t = (tree*)malloc(sizeof(tree));
    if (t != NULL)
        t->root = NULL;
    return t;
}

void insert(tree *tr, node *new)
{
    if (search(tr, new->key)) {
        printf("Chave %d ja existe na arvore!\n", new->key);
        return;
    }

    node *aux = NULL, *nd = tr->root;
    while (nd != NULL) {
        aux = nd;
        if (nd->key < new->key)
            nd = nd->right;
        else
            nd = nd->left;
    }

    if (aux != NULL) { /* não raiz */
        new->father = aux;
        if (aux->key < new->key)
            aux->right = new;
        else
            aux->left = new;
    } else { /* raiz */
        tr->root = new;
    }
}

int search(tree *tr, int key)
{
    node *nd = tr->root;
    while (nd != NULL) {
        if (nd->key == key) 
            return 1;
        else if (nd->key < key)
            nd = nd->right;
        else
            nd = nd->left;
    }
    return 0;
}
