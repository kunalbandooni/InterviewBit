bool pos = false;
int dp[1002][1002];
int find(int x,int y, int prev, int r, int c, vector<vector<int> > &A){
    if(x<0 || x>=r || y<0 || y>=c || A[x][y]<=prev)
        return INT_MIN;
    
    if(x==r-1 and y==c-1){
        pos = true;
        return 1;
    }
    
    if(dp[x][y]!=-1)
        return dp[x][y];
    
    int right = 1+find(x,y+1,A[x][y],r,c,A);
    int down =  1+find(x+1,y,A[x][y],r,c,A);
    return dp[x][y] = max(right,down);
}
int Solution::solve(vector<vector<int> > &A) {
    memset(dp, -1, sizeof dp);
    int r = A.size();
    int c = A[0].size();
    pos = false;
    int maxLen = find(0, 0, INT_MIN, r, c, A);
    return pos? maxLen: -1;
}
