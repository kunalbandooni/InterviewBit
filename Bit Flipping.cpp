int Solution::solve(int A) {
    vector<int>bit;
    while(A)
    {
        bit.push_back(A%2);
        A/=2;
    }
    for(int i=0;i<bit.size();i++)
    {
        bit[i]=!bit[i];
    }
    int ans=0;
    for(int i=0;i<bit.size();i++)
    {
        if(bit[i])
        ans+=(1<<i);
    }
    return ans;
}
