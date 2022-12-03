int Solution::solve(vector<vector<int> > &grid, int k ) {
    int m=grid.size();
    int n=grid[0].size();
     
    vector<vector<int>> dp(m+2 , vector<int>(n+2 , 0));
   
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i-1][j-1];
 
   
    // Now we have to find the k *k matrix ,
   
    int res=INT_MIN;
   
    for(int i=k;i<=m;i++){
        for(int j=k;j<=n;j++){
            int val = dp[i][j] - dp[i-k][j] - dp[i][j-k] + dp[i-k][j-k];
            res=max(res , val);
        }
    }
   
    return res;
}
