int Solution::solve(vector<string> &A) {
    // You can also use maps and check m.size() == 26
    int f[26]={0};
    for(int i=0;i<A.size();i++)
        for(int j=0;j<A[i].length();j++)
            f[A[i][j]-'a']++;
    for(int i=0;i<26;i++)
        if(!f[i])
            return 0;
    return 1;
}
