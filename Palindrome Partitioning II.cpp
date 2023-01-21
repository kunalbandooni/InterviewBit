bool ispalin(string A,int i,int j){
    while(i<=j){
        if(A[i++]!=A[j--])
            return false;
    }
    return true;
}
int cut(string A,int i, int j,vector< vector<int> >&dp,vector< vector<bool> >pd){
    if(ispalin(A,i,j)) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int n = A.length(),res = INT_MAX;
    for(int k = i;k<j;k++){
        if(pd[i][k])
            res = min(1 + cut(A,k+1,j,dp,pd),res);    
    }
    return dp[i][j] = res;  
}
int Solution::minCut(string A){
    int n = A.length();
    vector< vector<bool> >pd(n,vector<bool>(n));
    for(int i = 0;i<n;i++){
        for(int j = i;j<n;j++){
            pd[i][j] = ispalin(A,i,j);    
        }
    }
    vector< vector<int> >dp(n+1,vector<int>(n+1,-1));
    return cut(A,0,n-1,dp,pd);    
}
