int func(int i, int B, vector<int> &A, vector<vector<int>> &dp){
    if(B == 0)  return 1;
    if(i == -1)   return 0;
    
    if(dp[i][B] != -1)  return dp[i][B];
    
    if(B >= A[i]) // take
        return dp[i][B] = func(i-1, B, A, dp) or func(i-1, B - A[i], A, dp);
    else // not take
        return dp[i][B] = func(i-1, B, A, dp);
}
int Solution::solve(vector<int> &A, int B) {
    int n = A.size();
    vector<vector<int> > dp(n, vector<int> (B+1, -1));
    return func(n-1, B, A, dp);
}
