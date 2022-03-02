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
