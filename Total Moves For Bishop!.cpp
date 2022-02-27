int Solution::solve(int A, int B){
    int total=min(8-B,A-1)+min(A-1,B-1)+min(B-1,8-A)+min(8-A,8-B);
    return total;
}
