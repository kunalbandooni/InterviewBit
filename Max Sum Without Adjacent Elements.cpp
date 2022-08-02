int dp[20001];
int f(int i, vector<vector<int> > &A){
    if(i < 0)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    
    int take = max(A[0][i], A[1][i]) + f(i-2, A);
    int notTake = f(i-1, A);
    
    return dp[i] = max(take, notTake);
}
int Solution::adjacent(vector<vector<int> > &A) {
    int n = A[0].size();
    memset(dp, -1, sizeof(dp));
    return f(n-1, A);
}
