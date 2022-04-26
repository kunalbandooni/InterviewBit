int Solution::maxProfit(const vector<int> &A) {
    int n=size(A);
    if(n==0)
        return 0;
    int curr=A[0];
    int profit=0;
    for(int i=1;i<n;i++){
        if(A[i]<curr)
            curr=A[i];
        if(curr<A[i]){
            profit+=(A[i]-curr);
            curr=A[i];
        }
    }
    return profit;
}
