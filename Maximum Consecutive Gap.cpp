int Solution::maximumGap(const vector<int> &A) {
    if(A.size() < 2)   return 0;
    vector <int> B;
    for(int i=0;i<A.size();i++)
        B.push_back(A[i]);
    sort(B.begin(),B.end());
    int maxi=0;
    for(int i=0; i<B.size()-1 ;i++){
        int diff = B[i+1] - B[i];
        maxi = max(maxi, diff);
    }
    return maxi;
}
