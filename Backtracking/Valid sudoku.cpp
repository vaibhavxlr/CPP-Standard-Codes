class Solution {
public:
    
    bool check_box(int ans[][9], int row, int col) {
            int k;
        
            //first find row
            if(row < 3)
                k = 0;
            else if(row < 6) 
                k = 3;
            else if(row < 9)
                k = 6;
        
            //then find col
            int l;
            if(col < 3)
                l = 0;
            else if(col < 6) 
                l = 3;
            else if(col < 9)
                l = 6;
            
                
            for(int i = k; i < k + 3; i++) {
                
                for(int j = l; j < l + 3; j++) {

                    if(!(i == row && j == col)) {
                        
                        if(ans[i][j] == ans[row][col]) {

                           return false; 

                        }
                    }
                }
            }

            //cout << " reachd here";
            return true;
        
    }
    
    
    bool solver(int ans[][9]) {
        
        bool res;
        
        for(int i = 0; i < 9; i++) {
            
            for(int j = 0; j < 9; j++) {
                
                if(ans[i][j] == 0) {
                    continue;
                }
                
                else {
                    
                 int row = i;
                 int col = j;
                 int k = 0;
                    
                //checking in same row
                 while(k < 9) {
                     
                     if(k != col && (ans[row][col] == ans[row][k])) {
                         
                             return false;
                         
                     }
                     k++;
                 }
                    
                k = 0;
                
                while(k < 9) {
                     
                     if(k != row && (ans[row][col] == ans[k][col])) {
                         
                             return false;
                    
                     }
                    
                    k++;
                 }
                    
                 res = check_box(ans, row, col);
                 if(res == false) {
                     return res;
                 }
                    
              }
                
            }
        }

        return res;
        
        
        
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int ans[9][9]; //int board
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                
                if(board[i][j] == '.') {
                    ans[i][j] = 0;
                }
                else {
                    ans[i][j] = board[i][j] - '0';
                }
            }
            
        }
        
        return solver(ans);
    }
};