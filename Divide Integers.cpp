int Solution::divide(int A, int B) {
    if(B==0) return INT_MAX;
    if(A==0 || (A<B&&A>0)) return 0;
    if(B==1) return A;
    long long ans=0;
    int sign = (A<0&&B>0)||(A>0&&B<0) ? -1 : 1;
    A = A==INT_MIN ? INT_MAX : abs(A);
    B = B==INT_MIN ? INT_MAX : abs(B);
    while(A>=B){
        A=A-B;
        ans++;
    }
    ans=(ans>INT_MAX)?INT_MAX:ans;
    return ans*sign;
}
