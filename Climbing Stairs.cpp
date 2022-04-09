int Solution::solve(vector<int> &A) {
    int d[A.size()];
    d[0]=A[0];
    d[1]=A[0]+A[1];

    // slight modification to "stairs" problem
    for(int i=2;i<A.size();i++)
        d[i]=A[i]+min(d[i-1],d[i-2]);
    return d[A.size()-1];
}

/*int dp[100005];
int helper(vector<int> &a, int i){
    if(i >= a.size())
        return 1e9;
    if(i == a.size()-1)
        return a[i];
    if(dp[i]!=-1)
        return dp[i];
    
    int x = a[i] + helper(a, i+1);
    int y = a[i] + helper(a, i+2);

    return dp[i] = min(x,y);
}
int Solution::solve(vector<int> &A) {
    memset(dp, -1, sizeof(dp));
    int mini = helper(A,0);
    return mini;
}
*/
