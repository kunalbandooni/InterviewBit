int Solution::searchInsert(vector<int> &A, int B) {
    return lower_bound(A.begin(),A.end(),B) - A.begin();
    /*
    // Tried Binary Search successfully
    int n= A.size();
    int l=0,r=n-1,mid,ans;
    if(n==0 || B<A[0]) return 0;
    else if(B>A[n-1]) return n;
    while(l<=r){
        mid= l+(r-l)/2;
        if(A[mid]==B)
            return mid;
        else if(A[mid]>B){
            ans= mid;
            r= mid-1;
        }
        else
            l=mid+1;
    }
    return ans;*/
}
