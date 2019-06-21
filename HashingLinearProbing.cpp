#include <bits/stdc++.h>
using namespace std;
void linearProbing(int hash[],int hashSize,int arr[],int sizeOfArray);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int hashSize;
	    cin>>hashSize;
	    int hash[hashSize];
	    
	    
	    int  sizeOfArray;
	    cin>>sizeOfArray;
	    int arr[sizeOfArray];
	    
	    for(int i=0;i<sizeOfArray;i++)
	    cin>>arr[i];
	    
	    
	    
	    for(int i=0;i<hashSize;i++)
	    hash[i]=-1;
	    
	    linearProbing( hash, hashSize, arr, sizeOfArray);
	    
	    for(int i=0;i<hashSize;i++)
	    cout<<hash[i]<<" ";
	    
	    cout<<endl;
	    
	    
	}
	return 0;
}

void linearProbing(int hash[],int hashSize,int arr[],int sizeOfArray)
{
    for(int i=0;i<sizeOfArray;i++)
    {
        int temp = arr[i] % hashSize;
        if(hash[temp] == -1){
            hash[temp] = arr[i];
        }else{
            int totalit = 0;
            while(hash[temp]!=-1 && totalit < hashSize){
                temp++;
                if(temp == hashSize){
                    temp = 0;
                }
                totalit++;
            }
            
            if(totalit < hashSize){
                hash[temp] = arr[i];
            }
        }
    }
}
