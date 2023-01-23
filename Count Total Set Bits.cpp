int Solution::solve(int A) {
    A = A+1;  // as we have to check for 0 to A
    int mod = 1e9+7;
    int ans =0,p=1;
    //no of 1's at 0th place  = n/2 * 1+ max(n%2-1,0)
    //no of 1's at 1th place = n/2^2 * 2^1+ max (n%2^2-2^1,0);
    // no of 1's at 2nd place = n/2^3 * 2^2 + max( n%2^3 - 2^2,0);
          
    // for general case
    // at ith place = n/2^(i+1)*2^i + max(n% 2^(i+1)- 2^i,0);
    for(int i=0;i<=31;i++)
        ans = (ans%mod+ A/(int)pow(2,i+1)*(int)pow(2,i)%mod +max( A%(int)pow(2,i+1)-(int)pow(2,i),0)%mod)%mod;
    
    return ans;
}
