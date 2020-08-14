#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int>* print(int **graph, int V, int v1, int v2, bool *visible) {

    	  vector<int> *ans = new vector<int>;
          int sv = v1;
          queue<int> q;
    
          q.push(sv);
          visible[sv] = true;  // always mark visited when you are pushing in the queue;
		  
          unordered_map<int, int> mp;
          bool done = false;
    
          while(!done && !q.empty()) {
            int x = q.front(); 
            q.pop();
            for(int i = 0; i < V; i++)
                if(i != x && !(visible[i]) && (graph[x][i])) {
                    q.push(i), mp[i] = x;  
                    visible[i] = true;
                    if(i == v2) {
                        done = true;
                        break;
                    }
                    
             }
             
          }    
    	
          if(!done)
              return NULL;
    
          int compass = v2;
    	  ans -> push_back(v2);
    
    	  while(compass != v1) {
              compass = mp[compass];
              ans -> push_back(compass);
             
          }
   
    return ans;
   // }
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
    
    bool *visible = new bool[V];
    
    for(int i = 0; i < V; i++)
        visible[i] = false;
    
    
    vector<int> *ans = print(graph, V, v1, v2, visible);
    
    if(ans) {
        for(int i =  0; i < (*ans).size(); i++) {
            cout << ans  -> at(i) << " ";
        }
    }
    delete []visible;
    for(int i = 0; i < V; i++)
    	delete []graph[i];
    delete []graph;
    
    return 0;
}
