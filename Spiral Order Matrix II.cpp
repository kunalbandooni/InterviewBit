vector<vector<int> > Solution::generateMatrix(int A) {
    int n=A;
    vector<vector<int>> ans(n, vector(n, 0));
    int top=0, left=0, bottom=n-1, right=n-1;
    int val=1;
    while(val <= n*n){
    for(int i=left; i<=right; i++)
        ans[top][i] = val++;
    top++;
    for(int i=top; i<=bottom; i++)
        ans[i][right] = val++;
    right--;

    for(int i=right; i>=left; i--)
        ans[bottom][i] = val++;
    bottom--;
    
    for(int i=bottom; i>=top; i--)
        ans[i][left] = val++;
    left++;
    }
    return ans;
}
