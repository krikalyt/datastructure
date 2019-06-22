// Given two arrays A1[] and A2[] of size N and M respectively. The task is to sort A1 in such a way that the relative order among the elements will be same as those in A2. For the elements not present in A2, append them at last in sorted order. It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements.
#include<bits/stdc++.h>
using namespace std;
int main()
{
    // freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int test;
	cin >> test; 
	while(test--)
    {
        int M,N;
        cin >> M >> N;
        int arr[M];
        int brr[N];
        int crr[1000001] = {0};
        for(int i=0;i<M;i++)
        {
            cin >> arr[i];
            crr[arr[i]]++;
        }
        
        for(int i=0;i<N;i++)
        {
            cin >> brr[i];
        }
        

        for(int i=0;i<N;i++)
        {
            int temp = crr[brr[i]];
            while(temp--)
            {
                cout << brr[i] << " ";
            }

            crr[brr[i]]  = 0;
        }
        
        for(int i=0;i<1000001;i++){
            int temp = crr[i];
            while(temp--)
            {
                cout << i << " ";
            }

            crr[i]  = 0;
        }
        
        cout << '\n';
    }
	return 0;
}
