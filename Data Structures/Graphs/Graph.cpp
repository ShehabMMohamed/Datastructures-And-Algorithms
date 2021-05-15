#include "Graph.h"

Graph::Graph(const int& p_Vertices) : Vertices(p_Vertices) {
    AdjList = new vector<int>[Vertices];
}

void Graph::AddEdge(int u, int v) {
    AdjList[u].push_back(v);
}

void Graph::DFS(int src) {
    cout<<"Depth-First Search.\n";
    vector<bool> visited (Vertices, false);
    _DFS(src, visited);
    cout<<endl;
}
void Graph::_DFS(int src, vector<bool>& visited) {
    if(visited[src] == true)        // base case
        return;
    visited[src] = true;
    cout<<src<<" ";
    vector<int>::iterator i;
    for(i = AdjList[src].begin(); i != AdjList[src].end(); i++) {
        int node = *i;
        if(visited[node] == false) {
            _DFS(node, visited);
        }
    }
}
void Graph::BFS(int src) {
    cout<<"Breadth-First Search.\n";
    queue<int> q;
    vector<bool> visited (Vertices, false);
    q.push(src);
    visited[src] = true;
    vector<int>::iterator i;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(i = AdjList[u].begin(); i != AdjList[u].end(); i++) {
            int node = *i;
            if(visited[node] == false) {
                visited[node] = true;
                q.push(node);
            }
        }
    }
    cout<<endl;
}

Graph::~Graph() {
    delete []AdjList;
}

