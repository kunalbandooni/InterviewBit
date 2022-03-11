vector<int> Solution::findOccurences(vector<int> &A) {
    map<int,int>mp;
    for(int i=0;i<A.size();i++)
    {
        mp[A[i]]++;
    }
    vector<int>res;
    for(auto i:mp)
    {
        res.push_back(i.second);
    }
    return res;
}
