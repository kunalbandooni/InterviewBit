int Solution::solve(int A, int B, int C) {
    A=(A+C-1)%B;
    //A=A+C-1;
    //if(A>B)  A=A-B;
    return A;
}
