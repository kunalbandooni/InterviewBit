int Solution::solve(string A, int B) {
    int p=0,ans=0,c=0;
    for(int i=0;i<A.length();i++){
        if(p==B){
            ans=max(ans,c);
            c=0,p=0;
        }
        if(A[i]=='a') c++;
        p++;
    }
    ans=max(ans,c);
    return ans;
}
