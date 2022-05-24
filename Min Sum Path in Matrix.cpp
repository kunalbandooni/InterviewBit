int Solution::minPathSum(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    int dp[n+1];
    dp[0] =0;
    for(int i=1;i<=n;i++)
        dp[i] = dp[i-1]+A[0][i-1];

    for(int i=1;i<m;i++){
        for(int j=1;j<=n;j++){
            if(j==1)
                dp[j] = dp[j]+A[i][j-1];
            else
                dp[j] = min(dp[j], dp[j-1])+ A[i][j-1];
        }
    }
    return dp[n];
}
