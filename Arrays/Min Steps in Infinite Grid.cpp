#include <bits/stdc++.h>
#include <cmath>
int Solution::coverPoints(vector<int> &A, vector<int> &B) {
    int A_cur, B_cur;
    int i = 0, j = 0, count = 0;
    
    while(i < A.size() && j < B.size()){
         if(i == 0 && j == 0){
             A_cur = A[i++];
             B_cur = B[j++];
             continue;
           }
            count = count + max(abs(A[i] - A_cur),abs(B[j] - B_cur));
            A_cur = A[i++];
            B_cur = B[j++];
    }
        return count;
}

