int dp[1001][1001];
int f(int i, vector<int> a, vector<int> b, int c){
    if(c==0)    return 0;
    if(i == 0){
        if(c >= b[0])   return a[0];
        else    return 0;
    }
    if(dp[i][c]!=-1)    return dp[i][c];
    int notpick = f(i-1, a, b, c);
    int pick = 0;
    if(b[i] <= c)
        pick = a[i] + f(i-1, a, b, c-b[i]);
    return dp[i][c] = max(pick, notpick);
}
int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    memset(dp, -1, sizeof(dp));
    int n = A.size();
    return f(n-1, A, B, C);
}
