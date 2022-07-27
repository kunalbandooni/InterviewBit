/*
// PRO TIP :- USE MOST OPTIMIZED SOLUTION, EVEN BETTER THAN TABULATION
int dp[1000][3][2];
int f(int n, int k, int buy, vector<int> A){
    if(k==0)    return 0;
    if(n == A.size())   return 0;
    
    if(dp[n][k][buy]!=-1)   return dp[n][k][buy];    
    
    int profit = 0;
    if(buy)
        profit = max(-A[n] + f(n+1, k, 0, A),
                    0 + f(n+1, k, 1, A));
    else
        profit = max(A[n] + f(n+1, k-1, 1, A),
                    0 + f(n+1, k, 0, A));
        
    return dp[n][k][buy] = profit;
}
int Solution::maxProfit(const vector<int> &A) {
    //memset(dp,-1,sizeof(dp));
    
    //int n = A.size();
    //return f(0, 2, 1, A);
*/    


// CODE HERE
// TC: O(n*4)         SC: O(6)
int Solution::maxProfit(const vector<int> &A) {
    int n = A.size();
    vector<long long>after(6,0),curr(6,0);
    for(int ind =n-1;ind>=0;ind--){
        for(int buy=1;buy<=4;buy++){
            if(buy&1)
                curr[buy] = max(-A[ind]+after[buy+1],after[buy]);
            else
                curr[buy] = max(A[ind]+after[buy+1],after[buy]);
        }
        after = curr;
    }
    return after[1];
}
