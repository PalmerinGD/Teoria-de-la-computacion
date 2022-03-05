#include "mergeSort.h"

void sort(int arr[], int p, int q, int r)
{
    int tam1 = q - p + 1;
    int tam2 = r - q;
    int aux1[tam1];
    int aux2[tam2];

    for(int i=p; i <= q; i++)
        aux1[i-p] = arr[i];
    for(int i=q+1; i<=r; i++)
        aux2[i-q-1] = arr[i];

    int right = 0;
    int left = 0;
    for(int i=p; i<=r; i++)
    {
        if(left == tam1) arr[i] = aux2[right++];
        else if(right == tam2) arr[i] = aux1[left++];
        else if(aux1[left] <= aux2[right]) arr[i] = aux1[left++];
        else arr[i] = aux2[right++];
    }
}
void merge(int arr[], int p, int r)
{
    if(p < r)
    {
        int q = ((p + r) >> 1);
        merge(arr, p, q);
        merge(arr, q+1, r);
        sort(arr,p,q,r);
    }
}
