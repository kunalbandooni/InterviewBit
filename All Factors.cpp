vector<int> Solution::allFactors(int n) {
    int i;
    vector<int> ans;
    for(i=1;i*i<n;i++)
        if(n%i == 0)
            ans.push_back(i);
    if(i-(n/i) == 1)
        i--;
    for(;i>=1;i--)
        if(n%i == 0)
            ans.push_back(n/i);
    return ans;
}
