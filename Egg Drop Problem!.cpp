int f(int n, int k, vector<vector<int>> &dp){
    if(k == 0)    return 0;
    if(n == 0)    return 1e9;
   
    if(dp[n][k] != -1)    return dp[n][k];
   
    int mini = 1e9;
    int lo = 1, hi = k;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        int f1 = f(n - 1, mid - 1, dp);
        int f2 = f(n, k - mid, dp);
        mini = min(mini, 1 + max(f1,f2));
        if(f2 > f1)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return dp[n][k] = mini;
}

int Solution::solve(int n, int k) {  
    vector<vector<int>>dp(n + 1, vector<int>(k + 1, -1));
    return f(n, k, dp);  
}
