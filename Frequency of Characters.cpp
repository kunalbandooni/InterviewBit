vector<int> Solution::solve(string A) {
    vector<int> v;
    for(int i=0;i<26;i++)
        v.push_back(0);
    for(int i=0;i<A.size();i++)
        v[A[i]-'a']++;
    return v;
}
