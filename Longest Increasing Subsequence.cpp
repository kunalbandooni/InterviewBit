/*
There is a straight-forward Dynamic Programming solution in O(n^{2}) time. 
Though this is asymptotically equivalent to the Longest Common Subsequence
version of the solution, the constant is lower, as there is less overhead.

Let A be our sequence a_{1},a_{2},\ldots ,a_{n}. Define q_{k} as the length
of the longest increasing subsequence of A, subject to the constraint that
the subsequence must end on the element a_{k}. The longest increasing
subsequence of A must end on some element of A, so that we can find its 
length by searching for the maximum value of q. All that remains is to find
out the values q_{k}.

But q_{k} can be found recursively, as follows: consider the set S_{k} of 
all i<k such that a_{i}<a_{k}. If this set is null, then all of the elements
that come before a_{k} are greater than it, which forces q_{k}=1. Otherwise,
if S_{k} is not null, then q has some distribution over S_{k}. By the general
contract of q, if we maximize q over S_{k}, we get the length of the longest
increasing subsequence in S_{k}; we can append a_{k} to this sequence, to get that:

q_{k}=max(q_{j}|j\in S_{k})+1
If the actual subsequence is desired, it can be found in O(n) further
steps by moving backward through the q-array, or else by implementing
the q-array as a set of stacks, so that the above “+ 1” is accomplished
by “pushing” a_{k} into a copy of the maximum-length stack seen so far.

For more detailed explanation, refer the article-
https://www.interviewbit.com/blog/longest-increasing-subsequence/
*/

int Solution::lis(const vector<int> &a) {
    int n=a.size();
    vector<int> dp(n,0);
    dp[0]=1;
    for(int i=1;i<n;i++) {
        dp[i] = 1;
        for(int j=0;j<i;j++)
            if(a[i]>a[j])
                dp[i] = max(dp[i],1+dp[j]);
    }
    return *max_element(dp.begin(),dp.end());
}
