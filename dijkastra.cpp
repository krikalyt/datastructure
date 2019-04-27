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
        return p1.first>p2.first;
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
//     filei;
    short testcase;
    cin >> testcase;
    while(testcase--)
    {
        int N,M,S;
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
            edge[to-1].push_back(make_pair(cost,from-1));
        }
        
        cin >> S;
        dijkastra(S-1,abc,edge);
        for(int x : finalresult)
        {
            if(x==INT_MAX)
            {
                cout << -1 << " ";
            }
            else if(x==0)
            {
                
            }
            else{
                cout << x << " ";
            }
        }
        cout << endl;
        finalresult.clear();
    }
    return 0;
}

//testcase 1
/*
1
6 11
1 2 50
1 4 10
4 1 10
4 5 15
5 2 20
2 4 15
2 3 10
6 5 3
1 3 45
5 3 35
3 5 30
1
*/

//testcase 2
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
1
*/


//testcase 3
/*
1
6 8
1 2 2
2 4 7
1 3 4
2 3 1
5 4 2
5 6 5
4 6 1
3 5 3
1
*/


//tested for the problem https://www.hackerrank.com/challenges/dijkstrashortreach/problem
