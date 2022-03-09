/*
int Solution::trailingZeroes(int A) {
    int c=0;
    for(int i=5;A/i>=1;i=i*5)
        c=c+(A/i);
    return c;
}
*/
int Solution::trailingZeroes(int A) {
    int i=5;
    int ans = 0;
    while(A>=i){
        int x = A/i ;
        ans+=x;
        i*=5;
    }
    return ans;
}
