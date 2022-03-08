int Solution::solve(int A) {
    if(A&1)
        return 0;
    int count = 0;
    while ((A & 1) == 0){
        A = A >> 1;
        count++;
    }
    return count;
}
