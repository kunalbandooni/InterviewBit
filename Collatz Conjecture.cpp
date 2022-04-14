long Solution::solve(int A, int B) {
    long t = A;
    for(int i=1;i<B;i++){
        if(t%2 == 1)
            t = 3*t + 1;
        else
            t = t/2;
    }
    return t;
}
