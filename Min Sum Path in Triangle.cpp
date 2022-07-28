/*
// memomization gave TLE, so space optimized to O(2*n)
int dp[1001][1001];
int f(int i, int j, vector<vector<int>> A){
    if(i == A.size()-1)
        return A[i][j];
    
    if(dp[i][j]!=-1)    return dp[i][j];
    
    int down = A[i][j] + f(i+1,j,A);
    int diagonal = A[i][j] + f(i+1, j+1, A);
    
    return dp[i][j] = min(down,diagonal);
}*/
int Solution::minimumTotal(vector<vector<int> > &a) {
    int n = a.size();
    vector<int> dp(n, 0);
    //memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)
        dp[i] = a[n-1][i];
    
    for(int i = n-2;i>=0;i--){
        vector<int> temp(n, 0);
        for(int j=i;j>=0;j--){
            int d = a[i][j] + dp[j];
            int dg = a[i][j] + dp[j+1];
            temp[j] = min(d, dg);
        }
        dp = temp;
    }
    return dp[0];
    //return f(0, 0, A);
}
