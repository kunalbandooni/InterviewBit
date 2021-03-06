/*int dp[1001][1001];
int cal(int i,int j,vector<vector<int>> &A){
    if(i==A.size() || j==A.size())
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    return dp[i][j] = A[i][j] + max(cal(i+1,j,A),cal(i+1,j+1,A));
}
int Solution::solve(vector<vector<int>> &A){
    memset(dp, -1 ,sizeof dp);
    return cal(0,0,A);  
}
*/
int Solution::solve(vector<vector<int> > &a) {
    int n=a.size();
    for(int i=n-2;i>=0;i--)
        for(int j=0;j<a[i].size();j++)
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
    return a[0][0];
}
