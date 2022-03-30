int Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    vector<bool> m(n,false);
    for(auto i:A){
        if(m[i])
            return i;
        m[i]=true;
    }
    return -1;
}
