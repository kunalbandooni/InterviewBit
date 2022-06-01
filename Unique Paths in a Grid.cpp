int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int M = A.size(); int N = A[0].size();

    int dp[M+1][N+1]; 
    for(int i=0;i<=M;i++)
        dp[i][0]=0;
    for(int i=0;i<=N;i++)
        dp[0][i]=0;
            
    dp[1][1]=1;
    
    for(int i=1;i<=M;i++){
        for(int j=1;j<=N;j++){
            if(A[i-1][j-1]==0){
                if(i==1 and j==1)
                    continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
            else dp[i][j]=0;
        }
    }
    return dp[M][N];
}
