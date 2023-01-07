int Solution::motherVertex(int A, vector<vector<int> > &B) {
    map<int, int> mp;
    for(auto x : B){
        if(x[0] == x[1]) continue;
        mp[x[1]]++;
    }
    int cnt =0 ;
    for(int i=1; i<=A; i++){
        cnt += (mp.find(i) == mp.end());
    }
    return (cnt <= 1);
}
