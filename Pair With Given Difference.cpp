int Solution::solve(vector<int> &A, int B) {
    B=abs(B);
    int N=A.size();
    if(N==1) 
        return 0;
    sort(A.begin(),A.end());
    int start=0;
    int end=1;
    while(start<=end && start<=N-2 && end<=N-1){
        if(A[end]-A[start]==B){
            if(end!=start) return 1;
            else end++;
        }
        else if(A[end]-A[start]<B){
            end++;
        }
        else{
            if(A[end]<0) end++;
            else if(A[end]>=0 && A[start]<0 && end-start>1) start++;
            else start++;
        }
    }
    return 0;
}
