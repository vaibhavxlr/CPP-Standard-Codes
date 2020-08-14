class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool isrowzero = false;
        bool iscolzero = false;
        
        int col_count= matrix[0].size();
        int row_count = matrix.size();
        //cout << m << n;
        
        for(int i = 0; i < col_count; i++) {
            if(matrix[0][i] == 0){
                isrowzero = true;
                break;
            }
        }
        
      
        
        for(int i = 0; i < row_count; i++) {
            if(matrix[i][0] == 0){
                iscolzero = true;
                break;
            }
        }
        

        
        for(int i = 1; i < row_count; i++) {
            for(int j = 1; j < col_count; j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
              
            }
        }
        
        
        for(int j = 1; j < col_count; j++) {
            if(matrix[0][j] == 0) {
                for(int i =  1; i < row_count; i++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
    
        
        for(int i = 1; i < row_count; i++) {
            if(matrix[i][0] == 0) {
                for(int j =  1; j < col_count; j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        
    
        
        if(isrowzero) {
            for(int j = 0; j < col_count; j++) {
                matrix[0][j] = 0;
            }
        }
        
   
        
        if(iscolzero) {
            for(int i = 0; i < row_count; i++) {
                matrix[i][0] = 0;
            }
        }
        
  
        }
        
    
};