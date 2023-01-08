int Solution::cntBits(vector<int> &A) {
    const int M = 1e9 + 7;
    int i= 32, ones_ct = 0, zeros_ct = 0;
    long long sum = 0;
    while(i--)
    { 
        zeros_ct = 0, ones_ct = 0;
        for(int i=0; i<A.size(); i++)
        {
            if(A[i] & 1 == 1) ones_ct++;
            else zeros_ct++;
            A[i] = (A[i]>>1);
        }
        sum += (long long)2 * ones_ct * (zeros_ct);
    }
    return sum%M;
}
