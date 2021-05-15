#include <iostream>
#include "Graph.h"

// Lab Session 10 : Graphs

/*
    Test graph :

    0 <--- 4 <---- 1 ----> 6 ---> 8 ---> 9
                   ^
                   |
                   |
   5 ----> 2 ----> 3
                   |
                   |
                   v
                   7
 
 1) Depth-First Search (DFS)
 2) Breadth-First Search (BFS)
 DFS // 5, 2, 3, 7, 1, 6, 8, 9, 4, 0       
 BFS // 5, 2, 3, 7, 1, 6, 4, 8, 0, 9  
*/

int main() {
    
    Graph G(10);
    G.AddEdge(5, 2);
    G.AddEdge(2, 3);
    G.AddEdge(3, 7);
    G.AddEdge(3, 1);
    G.AddEdge(1, 6);
    G.AddEdge(1, 4);
    G.AddEdge(4, 0);
    G.AddEdge(6, 8);
    G.AddEdge(8, 9);
    
    G.BFS(5);
    G.DFS(5);
    
    return 0;
}
