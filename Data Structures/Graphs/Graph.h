#ifndef Graph_h
#define Graph_h
#include <iostream>
#include <vector>      
#include <queue>       
using namespace std;

class Graph {
private:
    vector<int>* AdjList;
    int Vertices;
    
    void _DFS(int src, vector<bool>& visited);
    
public:
    Graph(const int& p_Vertices);
    void AddEdge(int u, int v);
    void BFS(int src);
    void DFS(int src);
    ~Graph();
};


#endif 
