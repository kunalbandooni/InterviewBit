int Solution::trap(const vector<int> &A) {
    int l=0,r=A.size()-1;
    int lmax=0,rmax=0;
    int sum=0;
    while(l<r){
        if(A[l]<A[r])
        {
            if(A[l]<lmax)
                sum+=(lmax-A[l]);
            else
                lmax=A[l];
            l++;
        }
        else
        {
            if(A[r]<rmax)
                sum+=(rmax-A[r]);
            else
                rmax=A[r];
            r--;    
        }
    }
    return sum;
}
