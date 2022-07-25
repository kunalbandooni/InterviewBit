int f(int i, int j, string A, string B, vector<vector<int>> &dp){
    if(i == 0)  return j;
    if(j == 0)  return i;
    
    if(dp[i][j]!=-1)    return dp[i][j];
    
    int points = 0;
    if(A[i-1] == B[j-1])
        points = 0 + f(i-1, j-1, A, B, dp);
    else
        points = 1 + min(f(i,j-1,A,B, dp), min(f(i-1,j-1,A,B, dp),f(i-1,j,A,B, dp)));
    return dp[i][j] = points;
}
int Solution::minDistance(string A, string B) {
    int n = A.length();
    int m = B.length();
    
    vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
    
    return f(n, m, A, B, dp);
}
