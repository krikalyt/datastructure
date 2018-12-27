#include <iostream>
using namespace std;
void swap(int *a,int *b);
void insertionsort(int arr[],int number);
int main(void)
{
    int arr[] = {8,2,3,29,3,23,28,44};
    int num = sizeof(arr)/sizeof(int);
    insertionsort(arr,num);

    for(int i=0;i<num;i++)
        cout << arr[i] << endl;
    return 0;
}
void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}


void insertionsort(int arr[],int number)
{
    int key;
    int j;
    for(int i=1;i<number;i++)
    {
        j = i-1;
        key = arr[i];
        while(j>=0 && arr[j]>arr[j+1])
        {
            int temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            j = j-1;
        }
        arr[j+1] = key;
    }
}
