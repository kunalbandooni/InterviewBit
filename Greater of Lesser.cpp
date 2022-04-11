int Solution::solve(vector<int> &A, vector<int> &B, int C) {
    int c1=0,c2=0;
    for(int i=0;i<A.size();i++)
        if(C < A[i])
            c1++;
    for(int i=0;i<B.size();i++)
        if(C > B[i])
            c2++;
    return max(c1,c2);
}
