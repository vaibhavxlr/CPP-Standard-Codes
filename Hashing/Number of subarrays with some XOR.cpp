int Solution::solve(vector<int> &A, int B) {
    vector<int> p(A.size());
    
    p[0] = A[0];
    
    for(int i = 1; i < A.size(); i++) {
        p[i] = A[i] ^ p[i - 1];
    }
    
    unordered_map<int, int> mp;
    int ans = 0;
    
    for(int i = 0; i < A.size(); i++) {
        if(p[i] == B)
            ans++;
        if(mp.find(p[i] ^ B) != mp.end()) {
            ans += mp[p[i] ^ B];
        }
        mp[p[i]]++;
    }
    
    return ans;
}
























