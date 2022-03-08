vector<int> Solution::solve(string A) {
    unordered_map<int,int> m;
    for(int i=0;i<A.length();i++)
        m[A[i]]++;
    vector<int> v;
    auto i=m;
    for(int i=0;i<A.length();i++){
        if(m[A[i]]>0)
            v.push_back(m[A[i]]);
        m[A[i]]=0;
    }    
    return v;
}
