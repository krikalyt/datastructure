#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
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


    void BFS(int i)
    {
        if(i>=this->v)
        {
            return;
        }
        vector<bool> temp(this->v);
        for (int j = 0; j <temp.size(); ++j) {
            temp[i] = false;
        }

        queue<int> queue1;
        queue1.push(i);
        temp[i] = true;


        while (!queue1.empty())
        {
            int temp2 = queue1.front();
            cout << temp2 << endl;
            queue1.pop();
            for (int j:vertex[temp2]) {
                if(!temp[j])
                {
                    queue1.push(j);
                    temp[j] = true;
                }
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
    graph.BFS(0);


    return 0;
}
