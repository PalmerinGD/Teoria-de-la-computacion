#include "binarySearch.h"

int compare(Data data1, Data data2)
{
    if(data1.n > data2.n)
        return 1;
    if(data1.n < data2.n)
        return 0;
    return 2;
}

Nodo* createNodo(Data data)
{
    Nodo* temp = (Nodo*)malloc(sizeof(Nodo));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Nodo* insert(Nodo* root, Data data)
{
    if(root == NULL) return createNodo(data);

    int comp = compare(root->data, data);
    if(comp == BIGGER) 
    {
        root->left = insert(root->left, data);
        return root;
    }
    else if(comp == LOWER)
    {
        root->right = insert(root->right, data);
        return root;
    }

    return NULL;
}


Nodo* search(Nodo* root, Data data)
{
    if(root == NULL) return NULL;

    int comp = compare(root->data, data);
    if(comp == BIGGER)
        return search(root->left, data);
    else if(comp == LOWER)
        return search(root->right, data);
    return root;
}

void Inorder(Nodo* root)
{
    if(root == NULL) return;

    Inorder(root->left);
    printf("%d ", root->data.n);
    Inorder(root->right);
}
