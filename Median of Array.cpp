double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    int n=A.size();
    int m=B.size(); 
    if (n>m)
        return findMedianSortedArrays(B,A);
    if (n==0){ // no need to check for m as n<m for sure
        if (m%2==1)
            return B[m/2];
        else{
            double d1=B[m/2] ;
            double d2=B[m/2-1] ;
            return (d1+d2)/2 ;
        }
    }
    // the left partition will have half elements (less by 1 if odd)
        int half=(m+n)/2 ;
        int l=0;
        int r=n ;
    // idea is to do a BS on i 
    // j can be calculated as the size has to be ==half 
    // i denotes the number of elements in the left partition from A (0->n)
    // similarly j
        double ans=0 ;  
    while(l<=r){
        int i=l+(r-l)/2 ;       
        int j=half-i;
        // Al-> the highest element of A in left partition
        // Ar -> the smallest element of A in right partition
        // similarly Bl,Br
        int Al,Ar,Bl,Br ;
        if (i>=1) 
            Al=A[i-1] ;
        else 
            Al=(INT_MIN) ;
        if (i<n) 
            Ar=A[i] ;
        else 
            Ar=INT_MAX ;
        if (j>=1) 
            Bl=B[j-1] ;
        else 
            Bl=INT_MIN ;
        if (j<m) 
            Br=B[j] ;
        else 
            Br=INT_MAX ;
        // If we have partitioned correctly, the following if() must hold, so return the median accordingly
        if (Al<=Br && Bl<=Ar){
            if ((m+n)%2==1)
                return min(Ar,Br) ;
            else{
               double d1=max(Al,Bl) ;
                double d2=min(Ar,Br) ;
               return ((d1+d2)/2) ;
            }
        }
        if (Al>Br)
            // Al has to be decreased-> i has to be decreased-> bring right pointer down
            r=i-1;
        else
            // Bl>Ar 
            // Bl has to be decreased-> j has to be decreased-> i has to be increased
            l=i+1 ;
    }
    return ans ; // not needed
}
