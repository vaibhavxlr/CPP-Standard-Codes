#include <iostream>
using namespace std;

bool hasPath(int **graph, int V, int v1, int v2, bool *visited) {
    
    if(v1 == v2)
        return true;
    
    visited[v1] = true;
    for(int i = 0; i < V; i++) {
    	if(graph[v1][i] && !visited[i])  {
            if(hasPath(graph, V, i, v2, visited))
                return true;
        }
    }
    
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
	
    int **graph = new int*[V];
    
    for(int i = 0; i < V; i++) {
        graph[i] = new int[V];
        for(int j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
    
	for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    
    int v1, v2;
    cin >> v1 >> v2;
    
    
    bool *visited = new bool[V];
    
    for(int i = 0; i < V; i++)
        visited[i] = false;
    
    bool ans = hasPath(graph, V, v1, v2, visited);
    ans == true ? cout << "true" : cout << "false";
    
    delete []visited;
    for(int i = 0; i < V; i++)
    	delete []graph[i];
    delete []graph;
    
    
  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */

  return 0;
}
