vector<int> Solution::solve(vector<int> &A) {
    int n=A.size();
    vector<int> a;
    for(int i=0;i<n;i++)
        if(A[i])
            a.push_back(A[i]);
    int left=n-a.size();
    while(left--)
        a.push_back(0);
    return a;
}
