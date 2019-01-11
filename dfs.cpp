#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
void printall(int v,vector<bool> tobeprint)
{

}
struct Graph{
public:
    vector<int> *vertex;
    int v;
public:
    Graph(int v)
    {
        this->v = v;
        this->vertex = new vector<int>[v];
    }
    void addEdge(int from,int to)
    {
        this->vertex[from].push_back(to);
    }


    void DFS(int i)
    {
        if(i>=this->v)
        {
            return;
        }
        bool temp[this->v];
        for (int j = 0; j < v;j++) {
            temp[i] = false;
        }
        Helper(i,temp);
    }

    void Helper(int v,bool temp[])
    {
        temp[v] = true;
        cout << v << " ";
        for(auto it: this->vertex[v]) {
            if (!temp[it])
            {
                Helper(it,temp);
            }
        }
    }
};

int main(void)
{

    Graph graph(3);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(1,2);
    graph.DFS(0);
    return 0;
}
