int Solution::solve(vector<int> &A, int B) {
    int sum = 0,n = A.size();
    int start = B-1,end=n-1;
    for(int k=0; k<= start; k++)
        sum += A[k];

    int ans = INT_MIN;
    ans = max(sum,ans);
    while(end != n-B-1){
        sum += A[end];
        sum -= A[start];
        ans = max(sum,ans);
        start--;
        end--;
    }
    return ans;
}

// Reviewed someone's code, putting it here :D
/*
Try not to make a simple problem complex.

The problem statement says, "You can pick B elements from 
either left or right end of the array A to get maximum sum." 
So, middle elements won't ever be even seen by our 
traversing. All we need are the first and last 'B' elements 
(as we can pick from only left or right end of array).

What you can do is, first of all, check the sum for the 
first 'k' elements.

This is for cases like : 
A: [1,-20,1000,0,1,2,2,3,1,2] 
B: 3

Then, you can simply use the sliding window approach, by
adding the last elements and subtracting the first elements 
from the array.

Also, keep checking for maximum sum.
*/
