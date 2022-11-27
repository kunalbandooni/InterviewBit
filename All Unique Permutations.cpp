void helper(vector<int> &A, int l, int r, set<vector<int>>& res){
    if(l==r){
        res.insert(A);
        return;
    }

    for(int i=l;i<=r;i++){
        swap(A[l],A[i]);
        helper(A,l+1,r,res);
        swap(A[l],A[i]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    set<vector<int>> res;
    helper(A,0,A.size()-1, res);
    vector<vector<int>> ans;
    for(auto x:res)
        ans.push_back(x);
    return ans;
}
