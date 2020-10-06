#define MOD 1000000007

vector<int> Solution::repeatedNumber(const vector<int> &A) {
 
   long long sum = 0, sqd_sum = 0;
   
   
   for(int i : A) {
        sum += i;
        sqd_sum += ((long long)i * i);
   }
   
   int n = A.size();
   
   long long act_sum, act_sqd_sum;
   act_sum = n * (n + 1) / 2; //sum upto first n terms 
   act_sqd_sum = ((n * (n + 1) * (2 * n + 1)) / 6); //sum of squares of first n terms 
   
   //  let x is repeating and y is missing
   //  act_sum = sum - x + y
   //   =>P1 =  x - y = sum - act_sum
   //  
   //  act_sqd_sum = (sqd_sum) - (x * x) + (y * y)
   //   =>P2 = x^2 - y^2 = sqd_sum - act_sqd_sum
   //  
   // P3 = x + y = P2 / P1
   // so repeating number is  (P3 + P1) / 2 
   //  and missing number is (P3 - P1) / 2
   
   long long P1 = sum - act_sum;
   long long P2 = sqd_sum - act_sqd_sum;
   long long P3 = P2 / P1;
   
   long long repeat = (P3 + P1) / 2;
   long long miss = (P3 - P1) / 2;
   
   return {(int)repeat, (int)miss};
}
