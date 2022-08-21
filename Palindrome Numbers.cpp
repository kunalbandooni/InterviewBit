bool check(string s){
    int n=s.size();
    int i;
    for(i=0;i<n/2;i++)
        if(s[i]!=s[n-i-1])
            return false;
    return true;
}
int Solution::solve(int A, int B, int C) {
    int i;
    vector<int>pal;
    for(i=A;i<=B;i++)
        if(check(to_string(i)))
            pal.push_back(i);
    
    int l=0;
    int n=pal.size();
    int ans=0;
    i=0;
    while(i<n){
        while(i<n&&pal[i]-pal[l]<=C)
            i++;
        ans=max(ans,i-l);
        if(i==n)
            break;
        while(l<n&&pal[i]-pal[l]>C)
            l++;
    }
    return ans;
}
