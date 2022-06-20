vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    int n = A.size();
    set<vector<int> > s;
    for(int i=0;i<(1<<n);i++){
        vector<int> temp;
        for(int j=0;j<n;j++)
            if(i&(1<<j))
                temp.push_back(A[j]);
        sort(temp.begin(),temp.end());
        s.insert(temp);
    }
    vector<vector<int> > ans;
    
    for(auto it:s){
        ans.push_back(it);
    }
    return ans;
}
