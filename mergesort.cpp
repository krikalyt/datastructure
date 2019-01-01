#include <iostream>
using namespace std;
void merge(int arr[], int start, int middle, int last);
void mergesort(int arr[], int start, int last);
int main(int argm,char **args)
{
	int arr[] = { 8,22,10};
	merge(arr,0,1,2);
	for(int i=0;i<=2;i++)
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
void merge(int arr[], int start, int middle, int last)
{
	int sizeofone = middle - start + 1;
	int sizeoftwo = last - middle;
	int arr1[sizeofone];
	int arr2[sizeoftwo];

	for (int i = 0; i < sizeofone; i++)
	{
		arr1[i] = arr[i];
	}

	for (int i = 0; i < sizeoftwo; i++)
	{
		arr2[i] = arr[middle+1+i];
	}

	int totalsize = sizeofone + sizeoftwo;
	int f = 0;
	int s = 0;
    int i= start;

    while(f <= middle && s <= last)
    {
        if(arr1[f]<=arr2[s])
        {
            arr[i] = arr1[f];
            f++;
        }
        else{
            arr[i] = arr2[s];
            s++;
        }
        i++;
    }
    i--;

    while(f <= middle)
    {
        arr[i] = arr1[f];
        f++;
        i++;
    }

    while(s <= last)
    {
        arr[i] = arr1[s];
        s++;
        i++;
    }
}
