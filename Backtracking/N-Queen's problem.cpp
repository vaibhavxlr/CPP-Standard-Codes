#include <bits/stdc++.h>
class Solution {

    vector<vector<string>> ans;
    public:
    
    bool isSafe(int a[][100], int row, int col, int n) {
        
        for(int i = 0; i < row; i++) {
            if(a[i][col] == 1) {
                return false;
            }
        }
        
        int i = row, j = col;
        
        while(i >= 0 && j >= 0) {
            if(a[i][j] == 1) {
                return false;
            }
            i--;
            j--;
        }
        
        i = row, j = col;
        
        while(i >= 0 && j < n) {
            if(a[i][j] == 1) {
                return false;
            }
            i--;
            j++;
        }
        
        return true;
        
    }
    
    
    
    
    bool solve_Nqueen(int a[][100], int row, int n) {
        
        if(row == n) {
            
            vector<string> temp2;
            
            for(int i = 0; i < n; i++) {
                string temp = "";
                for(int j = 0; j < n; j++) {
                    if(a[i][j] == 1) {
                        temp = temp + 'Q';
                    }
                    else {
                        temp = temp + '.';
                    }
                    
                }
                temp2.push_back(temp);
            }
            
            ans.push_back(temp2);
            
            return false;
            
        }
        
       for(int j = 0; j < n; j++) {
           if(isSafe(a, row, j, n)) {
               
               a[row][j] = 1;
               
               bool solution = solve_Nqueen(a, row + 1, n);
               
               if(solution)
                   return true;
               
           }
           a[row][j] = 0;
           
       } 
        
      return false;   
    }
    
    
    vector<vector<string>> solveNQueens(int n) {
        
        int a[100][100];
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                a[i][j] = 0; 
            }    
         }
        
        solve_Nqueen(a, 0, n);
        return ans;
    }
    
};