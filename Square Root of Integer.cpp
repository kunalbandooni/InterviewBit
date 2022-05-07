/*
APPROACH ARE SAME :) 
just keeping my own code too
int sqrt_helper(int A, long long start, long long end){
    long long mid;
    long long ans;
    while(start <= end){
        mid = start + (end - start)/2;
        if(A <= mid*mid and (mid+1)*(mid+1)>A){
            ans = mid;
            break;
        }
        if(mid*mid > A){
            end = mid - 1;
            ans = end;
        }
        else
            start = mid + 1;
    }
    return ans;
}
int Solution::sqrt(int A) {
    if(A == 2)
        return 1;
    return sqrt_helper(A,0,A);
}
*/
int Solution::sqrt(int A) {
    if(A==1)
        return 1;
    long long int low=0,high=A/2;
    long long int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(mid*mid<=A and (mid+1)*(mid+1)>A)
            return mid;
        else if(mid*mid>A) 
            high=mid-1;
        else 
            low=mid+1;
    }
}
