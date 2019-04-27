#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
#include <climits>
#include <vector>
#include <math.h>
#define filei freopen("input.txt","r",stdin)
#define fileo freopen("output.txt","w",stdout);
#define other cout << "Test End Here" << endl;
#define FOR(a,b) for(int i=a;i<b;i++)
typedef long long int lli;
using namespace std;
vector<lli> finalresult;
class mycompare{
public:
    int operator() (const pair<int,int>& p1,const pair<int,int>& p2)
    {
        return p1.first<p2.second;
    }
};
void dijkastra(int source,vector<int> abc,vector<pair<int,int>> edge[])
{
    bool visited[abc.size()] = {false};
    finalresult[source] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>> , mycompare> pathcost;
    pathcost.push({0,source});
    while(!pathcost.empty())
    {
        if(visited[source])
        {
            pathcost.pop();
            source = (pathcost.top()).second;
            continue;
        }
        pathcost.pop();
        visited[source] = true;
        for(auto m : edge[source])
        {
            if(finalresult[m.second]>finalresult[source] + m.first)
            {
                finalresult[m.second] = finalresult[source] + m.first;
            }
            pathcost.push(make_pair(finalresult[m.second],m.second));
        }
        source = (pathcost.top()).second;
    }
}
int main(void)
{
    filei;
    short testcase;
    cin >> testcase;
    while(testcase--)
    {
        int N,M;
        cin >> N >> M;
        vector<int> abc(N);
        finalresult.resize(N);
        FOR(0,N)
        {
            finalresult[i] = INT_MAX;
            abc[i] = i;
        }
        vector<pair<int,int>> edge[N];
        FOR(0,M)
        {
            int from,to,cost;
            cin >> from >> to >> cost;
            edge[from-1].push_back(make_pair(cost,to-1));
        }
        
        dijkastra(5,abc,edge);
        for(int x : finalresult)
        {
            if(x==INT_MAX)
            {
                cout << "not possible" << endl;
            }
            else{
                cout << x << endl;
            }
        }
            
        finalresult.clear();
    }
    return 0;
}


//input.txt tested on
/*
1
6 10
1 2 4
1 3 12
1 4 18
2 3 7
2 4 8
2 5 9
3 5 3
5 6 2
6 5 2
5 2 9
/*
