vector<int> func(int A){
    vector<int> res(A+1);
    res[0]=1;
    for(int i=1;i<=A;i++)
        res[i] = res[i-1] * (A-i+1) / i;
    return res;
}
vector<vector<int> > Solution::solve(int A) {
    vector<vector<int>> v;
    if(A>=1)
        v.push_back({1});
    if(A>=2)
        v.push_back({1,1});
    for(int i=2;i<A;i++){
        vector<int> z;
        z = func(i);
        v.push_back(z);
    }
    return v;
}
