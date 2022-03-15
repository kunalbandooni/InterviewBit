int Solution::solve(string A) {
    bool num=false,lc=false,uc=false,sc=false;
    if(!(A.length()>=8 and A.length()<=15))
        return 0;
    for(int i=0;i<A.length();i++){
        if(A[i]>='a' and A[i]<='z')
            lc=true;
        else if(A[i]>='A' and A[i]<='Z')
            uc=true;
        else if(A[i]>='0' and A[i]<='9')
            num=true;
        else
            sc=true;
    }
    if(num and lc and uc and sc)
        return 1;
    return 0;
}
