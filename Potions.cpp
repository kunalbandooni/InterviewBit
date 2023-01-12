int dp[101][101];
vector<int> T;
int f(vector<int> A,int i,int j){
    if(i>=j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int ans=INT_MAX;
    for(int k=i;k<j;k++){
        int temp=f(A,i,k)+f(A,k+1,j)+((T[k+1]-T[i])%100)*((T[j+1]-T[k+1])%100);
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;  
}

int Solution::minSmoke(vector<int> &A) {
    T.clear();
    int c=0;
    T.push_back(0);
    for(int i=0;i<A.size();i++){
        c+=A[i];
        T.push_back(c);
    }
    memset(dp,-1,sizeof(dp));
    int i=0,j=A.size()-1;
    return f(A,i,j);
}
