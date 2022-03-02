int Solution::solve(int A) {
    if(A==0)
        return 0;
    int s=1;
    while(A){
        s=s*(A%10);
        A=A/10;
    }
    return s;
}
