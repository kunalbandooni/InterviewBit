int Solution::power(string A) {
    int i,n,sum,c;
    n=A.size();
    if(n==0){return 0;}
    for(i=0,sum=0;i<n;i++)
        sum+=(A[i]-'0');
    if(sum==1 && n==1){return 0;}
    while(!((A[n-1]-'0')&1)){
        for(i=0,c=0;i<n;i++){
            sum=c*10+(A[i]-'0');
            A[i]=(sum/2)+'0';
            c=sum%2;
        }
    }
    for(i=0,sum=0;i<n;i++)
        sum+=(A[i]-'0');
    if(sum==1)
        return 1;
    return 0;
}
