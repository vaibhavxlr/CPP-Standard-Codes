string get(string ans) {
    
    char ch = ans[0];
    int count = 1;
    string finalstring = "";
    
    for(int i = 1; i < ans.size(); i++) {
        if(ans[i] == ch) {
            count++;
        }
        else {
            finalstring += to_string(count) + ch;
            ch = ans[i];
            count = 1;
        }
    }
    finalstring += to_string(count) + ch;
    return finalstring;
}

string Solution::countAndSay(int A) {
    
    if(A == 0)
        return "";
    
    string ans = "1";
    
    if(A == 1)
        return ans;
        
    for(int i = 2; i <= A; i++) {
        ans = get(ans);
    }
    
    return ans;
    
}
