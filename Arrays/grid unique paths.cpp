class Solution {
public:
    
    long long int uniquePath2(int col, int row, long long int dp[101][101]){ 
        dp[row][col] = 1;
        
        for(int i = 1; i < row; i++ ) 
            dp[i][col] = 1;
        
        for(int i = 1; i < col; i++)
            dp[row][i] = 1;       
        
        
        for(int i = row - 1; i >= 0; i--) {
            for(int j = col - 1; j >= 0; j--) {
                
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            
            }
        }
        
        return dp[1][1];
    
    }
    
    long long int uniquePaths(int m, int n) {
        
      long long int dp[101][101];
      for(int i = 0; i < 101; i++){
          for(int j = 0; j < 101; j++){
              dp[i][j] = 0;
          }
      }
          
      
      return uniquePath2(m, n, dp);
        
    }
};