/*
# PYHTON CODE:
    
def chainPairs(A):
    row = len(A)
    col = len(A[0])
    t = []
    dp = [1]*row
    for i in range(row):
        for j in range(0,i):
            if A[i][0]>A[j][1]:
                dp[i] = max(dp[i],dp[j]+1)
    return max(dp)

class Solution:
    # @param A : list of list of integers
    # @return an integer
    def solve(self, A):
        return chainPairs(A)
*/
int func(std::vector<std::vector<int> > &v, int n, std::vector<int> &dp){
    int ans = 1;
    if(dp[n] != -1)
        return dp[n];
    
    for(int i=0; i<n; i++)
        if(v[i][1] < v[n][0])
            ans = max(ans, func(v, i, dp) + 1);

    return dp[n] = ans;
}
int Solution::solve(vector<vector<int> > &A){
    std::vector<int> dp(A.size()+100, -1);
    int ans = 1;
    for(int i=0; i<A.size(); i++)
        ans = max(ans, func(A, i, dp));
    return ans;
}
