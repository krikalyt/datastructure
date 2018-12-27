#include <iostream>
using namespace std;
void bubblesort(int arr[],int num);
int main()
{
    int arr[] = {12, 11,6, 13, 5, 6};
    bubblesort(arr,sizeof(arr)/sizeof(int));
    for(int i=0;i<sizeof(arr)/sizeof(int);i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}

void bubblesort(int arr[],int num)
{
    int temp;
        for(int i=0;i<num-1;i++)
        {
            for(int j=0;j<num-1-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
}
