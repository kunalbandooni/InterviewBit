vector<vector<int> > Solution::combine(int n, int k) {
    vector<vector<int>>ans;
    if (n<k) return ans;
   
    vector<int>v,v1;
    for(int i=1;i<=n;++i) v.push_back(i);
   
    for(int i=0;i<(1<<n);++i){
        if (__builtin_popcount(i)!=k) continue;
        v1.clear();
        for(int j=0;j<n;++j){
            if (i&(1<<j)) v1.push_back(v[j]);
        }
        ans.push_back(v1);
    }
   
    sort(ans.begin(),ans.end());
    return ans;
}
