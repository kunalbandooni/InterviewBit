int Solution::solve(vector<int> &A) {
    int n=A.size(),cnt=n;
    map<int,int> mp;
    for(int i=0;i<n;i++) 
        mp[A[i]]++;
    for(auto it:mp){
        cnt = cnt-it.second;
        if(cnt==it.first) 
            return 1;
    }
    return -1;
}
