#define MOD 1000000007
int Solution::solve(int A) {
    long f=1;
    for(int i=2;i<=A;i++)
        f=(f*i)%MOD;
    return (f*2)%MOD;
}
