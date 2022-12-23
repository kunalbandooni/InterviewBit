int max_func(int a, int b, int c) {
    int x = a > b ? a : b; 
    return x > c ? x : c;
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    int i = 0, j = 0, k = 0, ans = INT_MAX;
    while(i < A.size() && j < B.size() && k < C.size()) {

        int x = max_func(abs(A[i] - B[j]), abs(A[i] - C[k]), abs(C[k] - B[j]));
        ans = min(ans, x);
        if(A[i] <= B[j] && A[i] <= C[k]) i++;
        else if(B[j] <= A[i] && B[j] <= C[k]) j++;
        else k++;
    }
    return ans;
}
