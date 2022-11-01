int Solution::solve(vector<vector<int> > &A) {
    int ans=0;
    
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A[0].size();j++)
            if(A[i][j]==1){
                if(i&&j)
                    A[i][j] = min(min(A[i-1][j], A[i][j-1]), A[i-1][j-1])+1;
                ans = max(ans, A[i][j]);
            }
    
    return ans*ans;
}
