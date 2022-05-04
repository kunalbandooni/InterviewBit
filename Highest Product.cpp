/*
There are only two possibilites for the maximum number
 2 negatives and one postive or 3 positives,take the
 max of both the cases.
*/
int Solution::maxp3(vector<int> &A) {
    sort(A.begin(),A.end());
    int N = A.size();
    return max(A[0]*A[1]*A[N-1], A[N-1]*A[N-2]*A[N-3]);
}
