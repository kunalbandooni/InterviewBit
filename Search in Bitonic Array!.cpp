int binarySearch_left(vector<int> &A, int s,int e,int target){
    int mid = s +(e-s)/2;
    while(s<=e){
        if(target==A[mid])
            return mid;
        else if(target>A[mid])
            s=mid+1;
        else
            e=mid-1;
        mid=s+(e-s)/2;
    }
    return -1;
}
int binarySearch_right(vector<int> &A, int s,int e,int target){
    int mid=s+(e-s)/2;
    while(s<=e){
        if(target==A[mid])
            return mid;
        else if(target>A[mid])
            e=mid-1;
        else
            s=mid+1;
        mid=s+(e-s)/2;
    }
    return -1;
}
int peak(vector<int> &A, int s,int e){
    int mid = s+(e-s)/2;
    while(s<e){
    if(A[mid]<=A[mid+1])
       s=mid+1; 
    else
        e=mid;
    mid=s+(e-s)/2;
    }
    return s;
}
int Solution::solve(vector<int> &A, int B) {
    int e = A.size()-1;
    int p = peak(A,0,e);
    //search in the increasing region
    if(B == A[p])
        return p;
    int ans1 = binarySearch_left(A,0,p-1,B);
    int ans2 = binarySearch_right(A,p+1,e,B);
    if(ans1!=-1)
        return ans1;
    else
        return ans2;
}
