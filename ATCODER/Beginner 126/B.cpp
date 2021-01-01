#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main() {
	//string a = "";
	int H, W;
	cin >> H >> W;
	
	//for(int i = 0; i < N; i++) {
	//cout << N / W;
	//}
	int A[100][100];
	int min = INT_MAX;
	
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >>  A[i][j];
            if(A[i][j] < min)
                min = A[i][j];
        }
    }
    
    int total = 0;
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(A[i][j] > min)
                total += (A[i][j] - min);            
        }
    }
    
    cout << total;
    
	//cout << a;
}