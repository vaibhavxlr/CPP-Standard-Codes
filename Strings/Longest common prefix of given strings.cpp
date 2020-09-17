string Solution::longestCommonPrefix(vector<string> &A) {
    
    string ans = "";
    
    for(int i = 1; i < A.size(); i++) {
        string temp = "";
        int index = 0;
        
        while(A[i][index] == A[i - 1][index]) {
            temp += A[i][index];
            index++;
        }
        
        if(ans != "" && temp.size() < ans.size())
            ans = temp;
        else if(ans == "")
            ans = temp;
    }
    
    return ans;
}