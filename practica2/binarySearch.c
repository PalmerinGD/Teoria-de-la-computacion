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

    return root;
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

void copy(Nodo* r1, Nodo** base)
{
    if(r1 == NULL) return;
    if(search(*base, r1->data) == NULL)
        *base = insert(*base, r1->data);
    copy(r1->left, base);
    copy(r1->right, base);
}

void interseccion(Nodo* r1, Nodo* r2, Nodo** base)
{
    if(r1 == NULL) return;
    if(search(r2, r1->data) != NULL)
        *base = insert(*base, r1->data);
    interseccion(r1->left, r2, base);
    interseccion(r1->right, r2, base);
}

void MultiplicarUtil(Nodo** base, Nodo* r1, Data d1)
{
    if(r1 == NULL) return;
    Data temp;
    char *newWord;
    newWord = concatenacionUtil(r1->data.palabra, d1.palabra);
    int i = 0;
    while(newWord[i] != '\0')
    {
        temp.palabra[i] = newWord[i];
        i++;
    }
    temp.palabra[i] = '\0';
    *base = insert(*base, temp);
    MultiplicarUtil(base, r1->left,d1);
    MultiplicarUtil(base, r1->right,d1);
}

void Multiplicar(Nodo* r1, Nodo* r2, Nodo** base)
{
    if(r1 == NULL) return;
    MultiplicarUtil(base, r2, r1->data);
    Multiplicar(r1->left, r2, base);
    Multiplicar(r1->right, r2,base);
}