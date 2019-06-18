#include <iostream>
using namespace std;
//bubble sort
void bsort(int arr[],int n)
{
    for(int j=1;j<n;j++)
    {
        int swap = 0;
        for(int i=1;i<n;i++)
        {
            if(arr[i] < arr[i-1]){
                int temp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = temp;
                swap++;
            }
        }

        if(swap==0)
            break;
    }
}
//insertion sort
void isort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int key = arr[i];
        int start = i;
        while(start > 0 && arr[start-1] > key)
        {
            arr[start]  = arr[start-1];
            start--;
        }
        arr[start]  = key;
    }
}

int main(void)
{
  
  return 0;
}
