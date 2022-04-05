int Solution::maxProfit(const vector<int> &A) {
    if(A.size() <= 1)
        return 0;
    
    int n=A.size();
    
    // keep previous minimum in 'a'
    vector<int> a;
    int mini=A[0];
    a.push_back(mini);
    for(int i=1;i<n;i++){
        mini=min(mini,A[i]);
        a.push_back(mini);
    }
    
    // keep difference in 'b'
    vector<int> b;
    for(int i=0;i<n;i++)
        b.push_back(A[i] - a[i]);

    // find max difference
    int maxi=b[0];
    for(int i=0;i<n;i++)
        maxi = max(maxi, b[i]);

    return maxi;
}
