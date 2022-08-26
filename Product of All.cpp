vector<int> Solution::solve(vector<int> &A) {
    int n=A.size(),B[n],s=1000000007;
    long long int prefix[n],suffix[n],pro1=1,pro2=1;
    prefix[0]=1;
    suffix[n-1]=1;
    for(int i=1;i<n;i++)
        prefix[i]=(prefix[i-1]*A[i-1])%s;
    
    for(int k=n-2;k>=0;k--)
        suffix[k]=(suffix[k+1]*A[k+1])%s;
    
    vector<int> res;
    for(int l=0;l<n;l++)
        res.push_back((prefix[l]*suffix[l])%s);
    
    return res;
}
