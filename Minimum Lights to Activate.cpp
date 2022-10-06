int Solution::solve(vector<int> &A, int B) {
    int res=0;
    for(int i=0;i<A.size();i++){
        int c=0;
        for(int j=B-1+i;j>i-B+1;j--){
            if(A[j]==1){
                res++;
                c++;
                i=j+B;
                break;
            }
        }
        if(c==0)
            return-1;
    }
    return res;
}
