#include <bits/stdc++.h>
using namespace std;

int winesTD(int wines[], int start, int end, int size, int dp[][100]) {
  
    if(start > end) 
        return 0;
    
    if(dp[start][end] != 0)
        return dp[start][end];
        
    dp[start + 1][end] = winesTD(wines, start + 1, end, size, dp);
    dp[start][end - 1] = winesTD(wines, start, end - 1, size, dp);
    
    int year = (size - (end - start));
    int op1 = (wines[start] * year) + dp[start + 1][end];
    int op2 = (wines[end] * year) + dp[start][end - 1];
    
    return max(op1, op2);
    
}

int winesBU(int wines[], int size) {

    int dp[size][size];
    
    int j = 0;
    
    for(int i = 0; i < size; i++) {
        dp[i][j++] = size * (wines[i]); 
    }
    
    j = size - 1;
    int k = 1;
    int year = size - 1;
    
    while(j >= 0) {
        for(int i = 0; i <= j; i++) {
            int op1 = (year * wines[i + k]) + dp[i][i + k - 1];
            int op2 = (year * wines[i]) + dp[i + 1][i + k];
            dp[i][i + k] = max(op1, op2);
        }
        year--;
        j--;
        k++;
    }
    return dp[0][size - 1];
}


int main() {
    
    int wines[] = {2, 3, 5, 1, 4};
    int size = sizeof(wines) / sizeof(int);
    
    int dp[100][100];
    
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            dp[i][j] = 0;
            
    cout << winesTD(wines, 0, size - 1, size,  dp) << endl;
    
    cout << winesBU(wines, size);
    
    return 0;
}