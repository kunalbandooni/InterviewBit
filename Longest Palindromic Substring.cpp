string Solution::longestPalindrome(string A) {
    if(A.size()<=1) return A;
    int st=0,ed=0;
    int max_length=1;
    int n=A.size();
    //for odd length
    for(int i=0;i<n;i++){
        int l=i,r=i;
        while(l>=0&&r<n){
            if(A[l]==A[r]){
                l--;
                r++;
            }
            else
                break;
        }
        int len=r-l-1;
        if(len>max_length){
            max_length=len;
            st=l+1;
            ed=r-1;
        }
    }
    //even length
    for(int i=0;i<n;i++){
        int l=i,r=i+1;
        while(l>=0&&r<n){
            if(A[l]==A[r]){
                l--;
                r++;
            }
            else
                break;
        }
        int len=r-l-1;
        if(len>max_length){
            max_length=len;
            st=l+1;
            ed=r-1;
        }
    }
    return A.substr(st, max_length);
}
