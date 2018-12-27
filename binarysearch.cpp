#include <iostream>
#include <math.h>
using namespace std;
int binarysearch(int arr[],int element,int number);
int main(void)
{
    int abc[] = {1,5,9,14,15,18,29,339,492,2343,9999};

    cout << binarysearch(abc,998,sizeof(abc)/sizeof(int)) << endl;
    return 0;
}

int binarysearch(int arr[],int element,int number){

    int first,last,middle;
    first=0;
    last=number-1;
    middle = (first + last)/2;
    while(1)
    {
        if(arr[middle]==element)
        {
            return middle;
        }
        else if(arr[middle]<element)
        {
            first = middle+1;
            middle = (first+last)/2;
            if(first>last)
            {
                return -1;
            }
        }
        else if(arr[middle]>element)
        {
            last = middle-1;
            middle = ((first+last)/2);
            if(last<first){
                return -1;
            }
        }
        else{
            return -2;
        }
    }
}
