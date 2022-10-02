int dp[501][2][501];
int f(int i, int buy, int cap, vector<int> &A){
    if(cap == 0)    return 0;
    if(i == A.size())   return 0;
    
    if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
    
    int profit;
    if(buy)
        profit = max(-A[i] + f(i+1, 0, cap, A), 0 + f(i+1, 1, cap, A));
    else
        profit = max(A[i] + f(i+1, 1, cap-1, A), 0 + f(i+1, 0, cap, A));
        
    return dp[i][buy][cap] = profit;
}
int Solution::solve(vector<int> &A, int B) {
    memset(dp, -1, sizeof(dp));
    int n = A.size();
    B = min(B, n);
    return f(0, 1, B, A);
}
