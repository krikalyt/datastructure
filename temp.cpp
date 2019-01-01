#include <iostream>
using namespace std;
void merge(int arr[], int start, int middle, int last);
void mergesort(int arr[], int start, int last);
int main(int argm,char **args)
{
	int arr[] = { 8,22,18,43,45,12,13};
	mergesort(arr,0,6);
	for(int i=0;i<=6;i++)
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


	int f = 0;
	int s = 0;
    int i= start;

    while(f < sizeofone && s < sizeoftwo)
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

    while(f<sizeofone)
    {
        arr[i] = arr1[f];
        f++;
        i++;
    }

    while(s<sizeoftwo)
    {
        arr[i] = arr2[s];
        s++;
        i++;
    }
}
