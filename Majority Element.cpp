int Solution::majorityElement(const vector<int> &A) {
    map<int,int> m;
    for(int i=0;i<A.size();i++)
        m[A[i]]++;

    for(auto i:m)
        if(i.second > A.size()/2)
            return i.first;
    return -1;
}
