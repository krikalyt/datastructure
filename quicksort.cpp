#include <iostream>
using namespace std;
void QuickSort(int arr[],int startindex,int endindex);
int Partition(int arr[],int startindex,int endindex);
int main(int number,char **args)
{
    int arr[] = {4,5,8,3,12,10,7};
    int num = ((sizeof(arr)/sizeof(int)) -1);
    QuickSort(arr,0,num);
    for(int i=0;i<=num;i++)
        cout << arr[i] << endl;
    return 0;
}

void QuickSort(int arr[],int startindex,int endindex)
{
    if(startindex>=endindex)
    {
        return;
    }
    int pindex=Partition(arr,startindex,endindex);
    QuickSort(arr,startindex,pindex-1);
    QuickSort(arr,pindex+1,endindex);
}

int Partition(int arr[],int startindex,int endindex)
{
    int pivot=arr[endindex];
    int pindex = startindex;
    for(int i=startindex;i<=endindex;i++)
    {
        if(arr[i]<=pivot)
        {
            int temp = arr[i];
            arr[i] = arr[pindex];
            arr[pindex] = temp;
            pindex ++;
        }

    }
    pindex--;
    return pindex;
}
