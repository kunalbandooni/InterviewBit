int Solution::solve(vector<int> &A, int B) {
    int l=0;
    int h= A.size()-1;
    int count=0;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(A[mid]<=B)
            l=mid+1;
        if(A[mid]>B)
            h=mid-1;
    }
    return l;
}
