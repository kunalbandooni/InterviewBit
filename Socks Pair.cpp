int Solution::solve(vector<int> &A) {
    map<int,int> m;
    int pairs=0;
    for(int i=0;i<A.size();i++)
        m[A[i]]++;
    for(auto i:m){
        if(i.second>1)
            pairs+=(i.second/2);
    }
    return pairs;
}
