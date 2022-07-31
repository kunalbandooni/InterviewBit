void Solution::rotate(vector<vector<int> > &A) {
    for(int i=0;i<A.size();i++)
        for(int j=0;j<=i;j++)
            swap(A[i][j],A[j][i]);

    for(int i=0;i<A.size();i++)
        reverse(A[i].begin(),A[i].end());
}
