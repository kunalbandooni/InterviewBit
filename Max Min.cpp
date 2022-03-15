int Solution::solve(vector<int> &A) {
    int mini=A[0],maxi=A[0];
    for(int i=1;i<A.size();i++){
        mini=min(mini,A[i]);
        maxi=max(maxi,A[i]);
    }
    return maxi+mini;
}
