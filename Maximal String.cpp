string Solution::solve(string A, int B) {
    if(B==0)
        return A;
    int n=A.size();
    int a=stoi(A);
    int b=B;
    int max=0;
    for(int i=0; i<n-1;i++)
    {
        for(int j=i+1; j<n; j++)
        {
            string C=to_string(a);
            swap(C[i],C[j]);
            string ans=solve(C,b-1);
            int val=stoi(ans);
            if(val>max)
                max=val;
        }
    }
    return to_string(max);
}
