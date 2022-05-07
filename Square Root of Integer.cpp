int sqrt_helper(int A, long long start, long long end){
    long long mid;
    long long ans;
    while(start <= end){
        mid = start + (end - start)/2;
        if(A == mid*mid){
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
    return sqrt_helper(A,0,A);
}
