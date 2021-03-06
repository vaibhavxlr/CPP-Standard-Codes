#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int>* getPath(int **graph, int V, int v1, int v2, bool *visited) {
    
    if(v1 == v2) {
        //cout << v1 << " ";
        //visited[v1] = true;
		vector<int> *ans = new vector<int>;
        ans->push_back(v2);
        return ans;
    }
        
    visited[v1] = true;
    
    for(int i = 0; i < V; i++) {
    	if(graph[v1][i] && !visited[i])  {
            vector<int> *ans = getPath(graph, V, i, v2, visited);
            if(ans != NULL) {
                ans ->push_back(v1);
                return ans;
            }
        }
    }
    
   return NULL;
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
    
    vector<int> *ans = getPath(graph, V, v1, v2, visited);
    
    if(ans) {
        for(int i = 0; i < (*ans).size(); i++) {
            cout << ans -> at(i) << " ";
        }
    }
    //ans == true ? cout << "true" : cout << "false";
   
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
