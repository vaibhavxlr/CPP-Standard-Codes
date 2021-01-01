#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)

int visited[100001];
vector< vector<int> > adj(100001);

void dfs(int v) {

	visited[v] = 1;

	for(int i : adj[v]) {
		if(!visited[i])
			dfs(i);
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int V, E;
    
    cin >> V >> E;
    
    for(int i = 0; i < E; i++) {
    	int s, e;
    	cin >> s >> e;
    	adj[s].push_back(e);
    	adj[e].push_back(s);
	}
    
    int conn_comp = 0;
    
    for(int i = 1; i <= V; i++) {
    	if(!visited[i]) {
    		conn_comp++;
    		dfs(i);
		} 
	}
    
	cout << conn_comp;

    return 0;
}


