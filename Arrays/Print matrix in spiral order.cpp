vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    vector<int> ret;
    int C = 0;
    int CM = A[0].size() - 1;
    int R = 0;
    int RM = A.size() - 1;
    int dir = 0;
    //cout << C << CM << R << RM << endl;
    while((C <= CM) && (R <= RM)){
        if(dir == 0){
            for(int i = C; i <= CM; i++){
                ret.push_back(A[R][i]);
            }
            dir = 1;
            R++;
        }
        else if(dir == 1){
            for(int i = R; i <= RM; i++){
                ret.push_back(A[i][CM]);
            }
            dir = 2;
            CM--;
        }
        else if(dir == 2){
            for(int i = CM; i >= C; i--){
                ret.push_back(A[RM][i]);
            }
            dir = 3;
            RM--;
        }
        else if(dir == 3){
            for(int i = RM; i >= R; i--){
                ret.push_back(A[i][C]);
            }
            dir = 0;
            C++;
        }
        
        
        
    }
    // for(int itr = 0; itr < ret.size(); itr++){
    //     cout << ret[itr] << endl;
    // }
    return ret;
    
}