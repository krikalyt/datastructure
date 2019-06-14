#include <iostream>
using namespace std;
int lowerindex(int arr[],int start,int end,int search)
{
    if(start <= end)
    {
        int mid =  start + ((end-start)/2);
        if(arr[mid]==search && arr[mid-1]!=search)
            return mid;
        else if(search > arr[mid])
            return lowerindex(arr,mid+1,end,search);
        else
            return lowerindex(arr,start,mid-1,search);
    }
    return -1;
}
int main(void)
{
    return 0;
}
