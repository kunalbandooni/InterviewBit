int r,c,a[1005][1005],b[1005][1005];
long long dp[1005],mx[1005];
int Solution::solve(vector<vector<int> > &A, vector<vector<int> > &B) {
    long long ans=0,s=0;
    r=A.size();
    c=A[0].size();
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            a[i][j]=A[i][j];
            ans+=a[i][j];
        }
    }
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            b[i][j]=B[i][j];
            b[i][j]-=a[i][j];
        }
    }
    dp[0]=0;
    mx[0]=0;
    for(int i=1;i<=c;i++)
    {
        s+=b[0][i-1];
        dp[i]=s;
        mx[i]=max(mx[i-1],dp[i]);
    }
    for(int i=1;i<r;i++)
    {
        dp[0]=mx[0];
        s=0;
        for(int j=1;j<=c;j++)
        {
            s+=b[i][j-1];
            dp[j]=s+mx[j];
        }
        for(int j=1;j<=c;j++)
            mx[j]=max(mx[j-1],dp[j]);
    }
    return (ans+mx[c])%1000000007;
}
