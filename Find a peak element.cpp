// TC: O(logn)
int Solution::solve(vector<int> &a) {
    int l=0,h=a.size()-1;
    while(l<h)
    {
        int mid=l+(h-l)/2;
        if(a[mid]>a[mid+1])
        h=mid;
        else
        l=mid+1;
    }
    return a[l];
}

// TC: O(n)
/*
int Solution::solve(vector<int> &A) {
    int res=A[0];
    for(int i=0;i<A.size();i++){
        if(i!=0 and i!=A.size()-1){
            if(A[i]>=A[i+1] and A[i]>=A[i-1])
                return A[i];
        }
        else if(i==0 and A[0]>=A[1])
            return A[0];
        else if(i==A.size()-1 and A[i-1]<=A[i])
            return A[i];
    }
    return res;
}
*/
