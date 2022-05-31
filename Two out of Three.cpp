vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    map<int, set<int>> m;
    for(int i=0; i<A.size(); i++)
        m[A[i]].insert(0);
    for(int i=0; i<B.size(); i++)
        m[B[i]].insert(1);
    for(int i=0; i<C.size(); i++)
        m[C[i]].insert(2);

    vector<int> ans;
    for(auto i:m)
        if(i.second.size()>=2)
            ans.push_back(i.first);

    return ans;
}
