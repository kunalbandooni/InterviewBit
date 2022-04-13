vector<int> Solution::solve(string A) {
    vector<int> v;
    int ans=0;
    for(int i=0;i<A.size();i++){
        if(A[i] == ','){
            v.push_back(ans);
            ans = 0;
        }
        else
            ans = ans*10 + (A[i] - '0');
    }
    v.push_back(ans);
    return v;
}
