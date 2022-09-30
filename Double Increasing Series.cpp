int mod = 1e9+7;
int helper(int A, int len, vector<vector<int>> &dp){
    if(len == 1) return A; // A = 5, => {1 || 2 || 3 || 4 || 5}
    if(A == 0)   return 0; // A = 0 => no positives are present

    if(dp[A][len] != -1) return dp[A][len];

    int pick = helper(A/2, len-1, dp);
    int notPick = helper(A-1, len, dp);
    
    return dp[A][len] = (pick + notPick) % mod;
}
int Solution::solve(int A, int len) {
    vector<vector<int>> dp(A+1, vector<int>(len+1, -1));
    return helper(A, len, dp);
}
