int Solution::trailingZeroes(int A){
    int c=0;
    for(int i=5;A/i>=1;i=i*5)
        c=c+(A/i);
    return c;
}
