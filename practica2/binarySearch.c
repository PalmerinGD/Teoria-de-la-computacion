#include "binarySearch.h"

int compare(Data data1, Data data2)
{
    int lengthString1 = length(data1.palabra);
    int lengthString2 = length(data2.palabra);
    int i = 0;
    while(i < lengthString1 && i < lengthString2)
    {
        if(data1.palabra[i] < data2.palabra[i])
            return LOWER;
        else if(data1.palabra[i] > data2.palabra[i])
            return BIGGER;
        i++;
    }
    if(lengthString1 > lengthString2) return BIGGER;
    else if(lengthString1 < lengthString2) return LOWER;
    return EQUAL;
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
    printf("%s ", root->data.palabra);
    Inorder(root->right);
}

Nodo* copy(Nodo* r1, Nodo* base)
{
    if(r1 == NULL) return NULL;
    if(search(base, r1->data) == NULL)
        base = insert(base, r1->data);
    else if(base == NULL)
    base->left = copy(r1->left, base->left);
    base->right = copy(r1->right, base->right);
    return base;
}