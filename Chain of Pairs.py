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
