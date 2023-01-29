int Solution::solve(vector<vector<int> > &A){
    vector<vector<int>>dp(A.size()+1,vector<int>(A[0].size()+1,0));
    int ans=INT_MIN;
    for(int i=A.size()-1;i>=0;i--){
        for(int j=A[0].size()-1;j>=0;j--){
            dp[i][j]=dp[i+1][j]+dp[i][j+1]-dp[i+1][j+1]+A[i][j];
            ans=max(dp[i][j],ans);
        }
    }
    return ans;
}
