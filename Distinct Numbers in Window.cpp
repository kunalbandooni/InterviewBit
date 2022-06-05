vector<int> Solution::dNums(vector<int> &A, int B) {
    if(B > A.size())
        return {};
    
    vector<int> v;
    unordered_map<int,int> m;

    for(int i=0;i<B;i++)
        m[A[i]]++;

    for(int i=B; i<A.size(); i++){
        v.push_back(m.size());
        
        m[A[i-B]]--;

        m[A[i]]++;

        if(m[A[i-B]] == 0)
            m.erase(A[i-B]);
    }
    v.push_back(m.size());

    return v;
}
