/*

f(i, j) = |A[i] - A[j]| + |i - j| can be written in 4 ways 
(Since we are looking at max value, we don’t even care if
the value becomes negative as long as we are also covering 
the max value in some way).

(A[i] + i) - (A[j] + j)
-(A[i] - i) + (A[j] - j) 
(A[i] - i) - (A[j] - j) 
(-A[i] - i) + (A[j] + j) OR -(A[i] + i) + (A[j] + j)
Note that case 1 and 4 are equivalent and so are case 2 and 3.

We can construct two arrays with values: A[i] + i and A[i] - i.
Then, for above 2 cases, we find the maximum value possible. 
For that, we just have to store minimum and maximum values of 
expressions A[i] + i and A[i] - i for all i.


*/

int Solution::maxArr(vector<int> &a) {
    int max1(INT_MIN/2), max2(INT_MIN/2), min1(INT_MAX/2) , min2(INT_MAX/2);
    for(int i = 0;i<a.size();i++){
        max1 = max(max1, a[i]+i);
        min1 = min(min1, a[i]+i);
        max2 = max(max2,a[i]-i);
        min2 = min(min2,a[i]-i);
    }
    int ans1 = max1 - min1;
    int ans2 = max2 - min2;
    return max(ans1,ans2);
}
