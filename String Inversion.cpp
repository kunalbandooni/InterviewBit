string Solution::solve(string A) {
    string s="";
    for(int i=0;i<A.length();i++){
        if(A[i]>='a' and A[i]<='z')
            s+=(A[i]-32);
        else if(A[i]>='A' and A[i]<='Z')
            s+=(A[i]+32);
        else
            s+=A[i];
    }
    return s;
}
