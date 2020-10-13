vector<int> Solution::plusOne(vector<int> &A) {
    long long int total = 0; //tp calculate the total at each step
    vector<int> ret; //vector to be returned
    stack<int> st; //stack to hold values before transferring them into the new vector
    int carry = 0; 
        
    //base case(not in recursive sense), when there's only one digit    
    if(A.size() == 1){
        total = A[0] + 1; 
        if(total > 9){
                    ret.push_back(1);
                    ret.push_back(0);
                }
        else
         ret.push_back(total);
        
        return ret;
    }
    
    //other cases
    for(int i = A.size() - 1; i >= 0; i--){
        
        //if the digit is last, add 1 to it
        if(i == A.size() - 1) {
            //if the last digit is not equal to 9, simply add 1 and push the result in the stack
            if(A[i] != 9){
            
                st.push(A[i] + 1);
                continue;
                
            }
            //otherwise push zero in the stack and take 1 as carry
            else{
                
                st.push(0);
                carry = 1;
            
                
            }
            
        }
        
        //if the digit  is not the last one, we just have to add carry 
        //and keep forwarding till the digit at 0th index
        else{
                total = carry + A[i];
                
                //if total becomes greater than 9 i.e. 10
                if(total > 9){
                    st.push(0);
                    carry = 1;
                    
                    //if it is digit of 0th index, push 1 also in the stack meaning
                    //no need to take carry forward
                    if(i == 0){
                        st.push(1);
                    }
                }
                //if total is under 10 i.e. <= 9, just push the total in the stack
                else{
                    st.push(total);
                    carry = 0;
                }
        }
        
    }

    //empty the stack and push the elements in vector
    while(!st.empty()){
        ret.push_back(st.top());
        st.pop();
    }
    
    //to count number of zeros on left side
    int count = 0;
    
    for(int i = 0; i < ret.size(); i++){
        if(A[i] != 0){
            break;
        }
        count++;
    }
    
    //erase those zeroes counted above, as in our answer we don't need preceedin zeros
    ret.erase(ret.begin(), ret.begin() + count);
    return ret;
}
