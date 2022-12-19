int lcs(int m,int n,string &A,string &B,vector<vector<int>> &dp){
    if(m == 0 && n == 0)
        return 1;
    if(m == 0 && n != 0)
        return 0;
    if(m != 0 && n == 0)
        return 1;
    if(dp[m][n] != -1)
        return dp[m][n];

    if(A[m-1] == B[n-1])
        return dp[m][n] = lcs(m-1,n-1,A,B,dp) + lcs(m-1,n,A,B,dp);
    else
        return dp[m][n] = lcs(m-1,n,A,B,dp);
}
int Solution::numDistinct(string A, string B) {
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    return lcs(m,n,A,B,dp);
}
