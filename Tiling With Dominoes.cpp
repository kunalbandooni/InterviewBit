int Solution::solve(int A) {
    vector<int>da(A+1,0);
    vector<int>db(A+1,0);
    
    da[0]=1;
    da[1]=0;
    
    db[0]=0;
    db[1]=1;
    
    int MOD=1000000007;
    for(int i=2;i<A+1;i++){
        if(i%2==0){
            db[i]=0;
            da[i]=(da[i-2]+(2*db[i-1])%MOD)%MOD;
        }
        else{
            da[i]=0;
            db[i]=(da[i-1]+db[i-2])%MOD;
        }
    }
    return da[A];
}
