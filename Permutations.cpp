int n;
vector<vector<int>>perm;
vector<bool>chosen; // to keep
//  two mehods implemented
void solve(vector<int>&p,vector<int>&A){
    if(p.size() == n)
        perm.push_back(p);
    else{
        for(int i=0; i < n; i++){
            if(chosen[i])continue;
            chosen[i] = true;
            p.push_back(A[i]);

            solve(p,A);

            chosen[i] = false;
            if(!p.empty())
                p.pop_back();
        }
    }
}
void solve1(int k,vector<int>&p,vector<int>&A){
    if(k == n)
        perm.push_back(A);
    else{
        for(int i=k; i < n; i++){
            swap(A[i],A[k]);
            solve1(k+1,p,A);
            swap(A[i],A[k]);
        }
    }
}
vector<vector<int> > Solution::permute(vector<int> &A) {
    n = A.size();
    perm.clear();
    chosen.clear();
    vector<int>p;
    chosen.resize(n);

    // solve(p,A);
    solve1(0,p,A);

    return perm;
}
