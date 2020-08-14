//////method1
int knapsack(int* weights, int* values, int n, int maxWeight, int **ans) {
  if(n == 0 || maxWeight == 0) {
    return 0;
  }
  if(ans[n][maxWeight] != -1) {
    return ans[n][maxWeight];
  }
  if(weights[0] > maxWeight) {
    ans[n - 1][maxWeight] = knapsack(weights + 1, values + 1, n - 1, maxWeight, ans);
    ans[n][maxWeight] = ans[n - 1][maxWeight];
    return ans[n][maxWeight];
  }
  ans[n - 1][maxWeight - weights[0]] = knapsack(weights + 1, values + 1, n - 1, maxWeight - weights[0], ans);
  int a = ans[n - 1][maxWeight - weights[0]] + values[0];
  ans[n - 1][maxWeight] = knapsack(weights + 1, values + 1, n - 1, maxWeight, ans);
  ans[n][maxWeight] = max(a, ans[n - 1][maxWeight]);
  return ans[n][maxWeight];
}
int knapsack(int* weights, int* values, int n, int maxWeight){
  int *ans = new int[n + 1];
  for(int i = 0; i <= n; i++) {
    ans[i] = new int[maxWeight + 1];
    for(int j = 0; j <= maxWeight; j++) {
      ans[i][j] = -1;
    }
  }
  return knapsack(weights, values, n, maxWeight, ans);

} 


////////////////method 2
int knapsack(int* weights, int* values, int n, int maxWeight) {

  int *ans = new int[n + 1];
  for(int i = 0; i <= n; i++) {
    ans[i] = new int[maxWeight + 1];
  }
  for(int i = 0; i <= n; i++) {
    ans[i][0] = 0;
  }
  for(int j = 0; j <= maxWeight; j++) {
    ans[0][j] = 0;
  }
  
  for(int i = 1; i<= n; i++) {
    for(int j = 1; j <= maxWeight; j++) {
      if(weights[i - 1] <= j) {
        ans[i][j] = max(values[i - 1] + ans[i - 1][j - weights[i - 1]], ans[i - 1][j]);
      }
      else {
        ans[i][j] = ans[i - 1][j];
      }
    }
  }
  return ans[n][maxWeight];
}


//////////////method 3
int knapsack(int* weights, int* values, int n, int maxWeight) {
  int *ans = new int[maxWeight + 1];
  for(int i = 0; i <= maxWeight; i++) {
    ans[i] = 0;
  }
  
  for(int i = 0; i < n; i++) {
    for(int j = maxWeight; j >= weights[i]; j--) {
      ans[j] = max(ans[j], values[i] + ans[j - weights[i]]);
    }
  }
  return ans[maxWeight];
}