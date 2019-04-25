#ifndef Heap_File
#define Heap_File
#include <bits/stdc++.h>
#include <math.h>
using namespace std;
template<class heaptype>
class Heap{
private:
    vector<heaptype> HeapVector;
    int current = 0;
    void _addSwap(int current)
    {
        int parent = floor((current-1)/2);
        if(HeapVector[parent]<HeapVector[current] && current>0)
        {
            heaptype temp = HeapVector[parent];
            HeapVector[parent] = HeapVector[current];
            HeapVector[current] = temp;
            _addSwap(parent);
        }
    }
    void _delswap(int position)
    {
        int bigchildindex = comparetwo(position);
        if(HeapVector[bigchildindex] > HeapVector[position] && bigchildindex!=-1)
        {
            heaptype temp = HeapVector[position];
            HeapVector[position] = HeapVector[bigchildindex];
            HeapVector[bigchildindex] = temp;
            _delswap(bigchildindex);
        }
    }
    int comparetwo(int parent)
    {
        if((parent*2)+1 >= current) return -1;
        if((parent*2)+2 >= current) return (parent*2)+1;
        if(HeapVector[(parent*2)+1] > HeapVector[(parent*2)+2])
        {
            return (parent*2)+1;
        }
        return (parent*2)+2;
    }
public:
    Heap(int size)
    {
        HeapVector.resize(size);
    }
    void push(heaptype value)
    {
        if(current==HeapVector.size()) throw SEGV_MAPERR;
        HeapVector[current] = value;
        _addSwap(current);
        current++;
    }
    void pop()
    {
        if(current==0)
            throw SEGV_MAPERR;
        heaptype temp = HeapVector[0];
        HeapVector[0] = HeapVector[current-1];
        _delswap(0);
        current--;
    }
    heaptype top()
    {
        if(current==0) throw SEGV_MAPERR;
        return HeapVector[0];
    }
    int size() {return current;}
    bool empty() {return (current==0);}
};
#endif
