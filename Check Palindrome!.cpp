int Solution::solve(string A) {
    map<int,int> m;
    int n=A.length();
    for(int i=0;i<n;i++)
        m[A[i]]++;
    int c=0;
    for(auto i:m)
        if(i.second%2 == 1)
            c++;
    if(c > 1)
        return 0;
    return 1;
}
