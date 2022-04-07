vector<int> Solution::solve(vector<int> &A) {
    vector<int> v;
    int c=0;
    for(int i=0;i<A.size();i++){
        if(A[i] != 0 )
            v.push_back(A[i]);
        else
            c++;
    }
    for(int i=0;i<c;i++)
        v.push_back(0);
    return v;
}
