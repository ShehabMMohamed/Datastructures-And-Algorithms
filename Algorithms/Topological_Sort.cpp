#include <iostream>
#include <list>
#include <vector>
#include <stack>

class Graph {
private:
	int V;
	std::list<int> *adj;
public:
	Graph(int vertices) : V (vertices) {
		adj = new std::list<int>[V];
	}
	void add_edge(const int& u, const int& v) {
		adj[u].push_back(v);
	}
	void construct_graph(const std::vector<std::vector<int>>& test_graph) {
		for(int i = 0; i < test_graph.size(); i++)
			add_edge(test_graph[i][0], test_graph[i][1]);
	}
	void TopSort() {
		std::stack<int> temp_stack;
		std::vector<bool> visited(V, false);
		for(int i = 0; i < V; i++)
			if(!visited[i])
				TopSortUtility(i, visited, temp_stack);
		while(!temp_stack.empty()) {
			std::cout<<temp_stack.top()<<" ";
			temp_stack.pop();
		}
		std::cout<<std::endl;
	}

	void TopSortUtility(const int& u, std::vector<bool>& visited, std::stack<int>& temp_stack) {
		visited[u] = true;
		std::list<int>::iterator it;
		for(it = adj[u].begin(); it != adj[u].end(); it++) {
			if(!visited[*it])
				TopSortUtility(*it, visited, temp_stack);
		}
		temp_stack.push(u);
	}
	~Graph() {}
};

int main() {
	/*	
	GRAPH 1
		5 -> 2 -> 3
		|		  |
		v         v
		0 <- 4 -> 1
	*/
	std::vector<std::vector<int>> test_graph1 = {{5,2}, {5,0}, {4,0}, {4,1}, {2,3}, {3,1}};
	/*	
	GRAPH 2
		0 -> 1 
		|	 |	  
		v    v     
		2 -> 3
	*/
	std::vector<std::vector<int>> test_graph2 = {{0,1}, {0,2}, {1,3}, {2,3}};
	Graph G1 = Graph(6);
	Graph G2 = Graph(4);
	G1.construct_graph(test_graph1);
	G1.TopSort();
	G2.construct_graph(test_graph2);
	G2.TopSort();

	return 0;
}
