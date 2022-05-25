int solve(int A, int B,int i, int j){
    if(A==i || B==j)
        return 1;
    return solve(A,B,i+1,j) + solve(A,B,i,j+1);
}
int Solution::uniquePaths(int A, int B) {
    int ans;
    ans = solve(A-1,B-1,0,0);
    return ans;
}
