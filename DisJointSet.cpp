//problem link - https://www.hackerrank.com/challenges/merging-communities/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct DJS{
    
    vector<int> abc;
    DJS(int size)
    {
        abc.resize(size);
        for(int i=0;i<size;i++)
            abc[i] = -1;
    }

    int find(int x)
    {
        if(abc[x] < 0){
            return x;
        }
        int par = find(abc[x]);
        abc[x] = par;
        return par;
    }

    void insert(int x,int y)
    {
        int px = find(x);
        int py = find(y);
        if(px == py)
            return;

        int eleinxg = abs(abc[px]);
        int eleinyg = abs(abc[py]);
        if(eleinxg > eleinyg)
        {
            abc[py] = px;
            abc[px] = 0-(eleinxg + eleinyg);
        }else{
            abc[px] = py;
            abc[py] = 0-(eleinxg + eleinyg);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N,Q;
    cin >> N >> Q;
    DJS djs = DJS(N+1);
    while(Q--)
    {
        char c;
        cin >> c;
        if(c=='M'){
            int a,b;
            cin >> a >> b;
            djs.insert(a,b);
        }else if(c=='Q'){
            int a;
            cin >> a;
            cout << 0 - djs.abc[djs.find(a)] << '\n';
        }
    }
    return 0;
}
