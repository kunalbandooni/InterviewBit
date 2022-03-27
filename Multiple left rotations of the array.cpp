vector<vector<int> > Solution::solve(vector<int> &A, vector<int> &B) {
    vector<vector<int>> v;

    // This was required as the size 
    //      given in B exceeds A.size()
    for(int i=0;i<B.size();i++)
        B[i]=B[i]%A.size();
    
    for(long i=0;i<B.size();i++){
        long l=B[i];
        vector<int> z;
        while(l<A.size()){
            z.push_back(A[l++]);
        }
        l=0;
        while(l<B[i]){
            z.push_back(A[l++]);
        }
        v.push_back(z);
    }
    return v;
}
