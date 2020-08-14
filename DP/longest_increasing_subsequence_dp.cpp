 using namespace std;

 int lis(int arr[], int n) {
		
				
	/*Write your code here. 
	 *Don't write main().
	 *Don't take input, it is passed as function argument.
	 *Don't print output.
	 *Taking input and printing output is handled automatically.
	*/ 
     int dp[n];
     for(int i = 0; i < n; i++)
         dp[i] = 1;
     
     //dp[0] = 1;
     
     for(int i = 1; i < n; i++) {
         int temp = i - 1;
         while(temp >= 0) {
             if(arr[temp] < arr[i]) {
                 dp[i] = max(dp[i], dp[temp] + 1);
             }
             temp--;
         }
     }
     
     int maxim = 0;
     
     for(int i : dp) {
         if(i > maxim)
             maxim = i;
     }
  
     return maxim;
 }