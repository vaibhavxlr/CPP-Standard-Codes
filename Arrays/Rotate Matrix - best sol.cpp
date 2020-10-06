void Solution::rotate(vector<vector<int> > &A) {

   for(int i = 0; i < A.size(); i++) {
       reverse(A[i].begin(), A[i].end());
   }
    
   for(int i = 0; i < A.size(); i++) {
       for(int j = 0; j < A[0].size() - i; j++) {
           if(j != A[0].size() - 1 - i) {
               swap(A[i][j], A[A[0].size() - 1 - j][A[0].size() - 1 - i]);
           }
       }
   }
}