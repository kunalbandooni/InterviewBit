int Solution::coinchange2(vector<int> &A, int B) {
    int ways[B+1];
    memset(ways, 0, sizeof(ways));
    ways[0] = 1;
    for(int i = 0; i < A.size(); i++){
        for(int j = A[i]; j <= B; j++){
            ways[j] = ways[j] + ways[j-A[i]];
            ways[j] = ways[j]%1000007;
        }
    }
    return ways[B];
}







/*

int mod = 1e6+7;
int f(int i, int target, vector<int> A, vector<vector<int>> &dp){
    if(target == 0)
        return 1;
    if(i == 0){
        if(target % A[0] == 0)  return 1;
        return 0;
    }
    
    if(dp[i][target] != -1) 
        return dp[i][target];
    
    int notpick = f(i-1, target, A, dp);
    int pick = 0;
    if(target >= A[i])
        pick = f(i, target - A[i], A, dp);
        
    return dp[i][target] = (pick + notpick)%mod;
}
int Solution::coinchange2(vector<int> &A, int B) {
    int n = A.size()-1;
    vector<vector<int>> dp(n+1,vector<int> (B+1,-1));
    
    for(int i = 0;i<=B;i++){
        if(B%A[i] == 0) 
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }
    
    for(int i=1;i<=n;i++)
        for(int target = A[i];target<=B;target++){
            int notpick = dp[i-1][target]%mod;
            int pick = 0;
            if(target >= A[i])
                pick = dp[i][target - A[i]]%mod;
        
            dp[i][target] = (pick + notpick)%mod;
        }
    return dp[n][B] % mod;
    //return f(n, B, A, dp)%mod;
}
*/
