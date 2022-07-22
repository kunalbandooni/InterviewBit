int Solution::solve(string A, string B) {
    int n=A.size();
    int m=B.size();
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++)   dp[0][i]=0;
    for(int j=0;j<=m;j++)   dp[j][0]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<m+1;j++){
            if(A[i-1]==B[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
