vector<int> Solution::solve(vector<int> &A) {
    unordered_map<int, int> mp;
   
    for(int i = 0; i < A.size(); i++){
        auto itr = mp.find(A[i]);
        if(itr == mp.end())
            mp.insert({A[i], i});
        else{
            A[itr->second]++;
            mp[A[itr->second]] = itr->second;
            mp[A[i]] = i;
        }
    }
   
    return A;
}
