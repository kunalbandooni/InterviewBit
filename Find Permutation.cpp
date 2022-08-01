vector<int> Solution::findPerm(const string A, int B) {
    vector<int> ans(B,0);
    int i=B,j=1;
    int t=0;
    for(int k=0;k<B;k++){
        if(A[t]=='D'){
            ans[k]=i;
            i--;
        }
        else{
            ans[k]=j;
            j++;
        }
        t++;
    }
    return ans;
}
