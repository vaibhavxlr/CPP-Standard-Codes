int Solution::isPalindrome(string A) {
    
    
    string temp = "";
    
    for(int i = 0; i < A.size(); i++)
        if(isalnum(A[i]))
            temp += (char)tolower(A[i]); //use shorthand notation always
        
    int first = 0, last = temp.size() - 1;
    int ans;
    
    while(first <= last) {
        if(temp[first] != temp[last])
            return 0;
        first++, last--;
    }
    
    return 1;
}