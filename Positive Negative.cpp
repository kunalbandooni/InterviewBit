vector<int> Solution::solve(vector<int> &A) {
    int p=0,n=0;
    for(int i=0;i<A.size();i++)
        if(A[i]>0)
            p++;
        else if(A[i]<0)
            n++;
    return {p,n};
}
