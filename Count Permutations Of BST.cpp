int fact[55];
int factInv[55];
int dp[55][55][2];
int mod = 1e9+7;

int expoPow(int base,int p){
    int ans = 1;
    while(p){
        if(p%2) ans = (1ll*ans*base)%mod;
        base = (1ll*base*base)%mod;
        p /= 2;
    }
    return ans;
}

int rec(int index,int height,int isFull){
    if(index<=1){
        if((height==0)&&(isFull)) return 1;
        else if((!isFull)&&(height>0)) return 1;
        return 0;
    }
   
    if(height==0) return 0;
    if(dp[index][height][isFull]!=-1) return dp[index][height][isFull];
   
    int ans = 0;
    for(int i=1;i<=index;i++){
        int leftNum = i-1;
        int rightNum = index-i;
        int oneInstance = 0;
        if(isFull){
            oneInstance += (1ll*rec(leftNum,height-1,0)*rec(rightNum,height-1,1))%mod;
            oneInstance %= mod;       
            oneInstance += (1ll*rec(leftNum,height-1,1)*rec(rightNum,height-1,0))%mod;
            oneInstance %= mod;
            oneInstance += (1ll*rec(leftNum,height-1,1)*rec(rightNum,height-1,1))%mod;
            oneInstance %= mod;
        }
        else{
            oneInstance += (1ll*rec(leftNum,height-1,0)*rec(rightNum,height-1,0))%mod;
            oneInstance %= mod;
        }
       
        int multFact = (1ll*fact[index-1]*factInv[leftNum])%mod;
        multFact = (1ll*multFact*factInv[rightNum])%mod;
        oneInstance = (1ll*oneInstance*multFact)%mod;
        ans += oneInstance;
        ans %= mod;
    }
    return dp[index][height][isFull] = ans;
}

int Solution::cntPermBST(int A, int B){
    fact[0] = 1;
    for(int i=1;i<55;i++) fact[i] = (1ll*fact[i-1]*i)%mod;
    factInv[54] = expoPow(fact[54],mod-2);
    for(int i=53;i>=0;i--) factInv[i] = (1ll*factInv[i+1]*(i+1))%mod;
    memset(dp,-1,sizeof(dp));
    return rec(A,B,1);
}
