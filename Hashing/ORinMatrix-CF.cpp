#include<bits/stdc++.h>
#pragma gcc optimize("ofast")
using namespace std;
typedef long long int lli;
#define endl "\n";
#define mod 1000000007
#define fLoop for(lli i = 0; i < N; i++)
int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli M, N;
    cin >> M >> N;

    lli B[M][N], A[M][N];

    for(int i = 0; i < M; i++) {
    	for(int j = 0; j < N; j++) {
    		cin >> B[i][j];
    		A[i][j] = 1;
    	}
    }

	for(int i = 0; i < M; i++) {
    	for(int j = 0; j < N; j++) {
    		if(B[i][j] == 0) {
    				for(int k = 0; k < M; k++) A[k][j] = 0;
    				for(int k = 0; k < N; k++) A[i][k] = 0;
	    	}
    	}
    }

    //int p;

    for(int i = 0; i < M; i++) {
    	for(int j = 0; j < N; j++) {
    		int p = 0;
    		for(int k = 0; k < M; k++) p |= A[k][j];
    		for(int k = 0; k < N; k++) p |= A[i][k];
    	
	    	if(p != B[i][j]) {
	    		cout << "NO" << endl;
	    		return 0;
	    	}
    	}
    }

    cout << "YES" << endl;
    for(int i = 0; i < M; i++) {
    	for(int j = 0; j < N; j++) {
    		cout << A[i][j] << " ";
    	}
    	cout << endl;
    }
    return 0;
}	

    
