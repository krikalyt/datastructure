#include <iostream>
using namespace std;
void merge(int arr[], int first, int m, int last);
void mergesort(int arr[], int start, int last);
int main(int argm,char **args)
{
    int arr[] = { 8,-12,22,18,25,29};
    mergesort(arr,0,5);
    for(int i=0;i<=5;i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}
void mergesort(int arr[], int start, int last)
{
    if (start < last)
    {
        int middle = start + ((last - start) / 2);
        mergesort(arr, start, middle);
        mergesort(arr, middle+1, last);
        merge(arr, start, middle, last);
    }
}


void merge(int arr[], int first, int middle, int last)
{
    int sizeofone = middle - first + 1;
    int sizeoftwo =  last - middle;


    int *Left = new int[sizeofone];
    int *Right = new int[sizeoftwo];

    for (int i = 0; i < sizeofone; i++)
        Left[i] = arr[first + i];
    for (int i = 0; i < sizeoftwo; i++)
        Right[i] = arr[middle + 1+ i];

    int i = 0;
    int j = 0;
    int k = first;
    
    while (i < sizeofone && j < sizeoftwo)
    {
        if (Left[i] <= Right[j])
        {
            arr[k] = Left[i];
            i++;
        }
        else
        {
            arr[k] = Right[j];
            j++;
        }
        k++;
    }
    
    while (i < sizeofone)
    {
        arr[k] = Left[i];
        i++;
        k++;
    }
    while (j < sizeoftwo)
    {
        arr[k] = Right[j];
        j++;
        k++;
    }
}
