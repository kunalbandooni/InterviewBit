int mod = 1e9+7;
int Solution::solve(int A) {
    long long prev1 = 24, prev2 = 12, temp1, temp2;
    for(int i=2; i<=A; i++){
        temp1 = prev1;
        temp2 = prev2;
        prev1 = ((temp1 * 11)%mod + (temp2 * 10)%mod)%mod;
        prev2 = ((temp1 * 5)%mod + (temp2 * 7)%mod)%mod;
    }
    return (prev1 + prev2)%mod;
}
