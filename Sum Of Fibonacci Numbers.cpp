int func(vector<int> &fib , int i , int &count , int val , int sum , int taken , vector<vector<int>> &dp ){
    if(sum==val){
        if(count > taken)
            count = taken;
        return 0;
    }
    if(i<0)
        return INT_MIN;
    if(sum>val)
        return INT_MIN;
    if(dp[i][taken]!=-1)
        return dp[i][taken];
   
    // take or not take , unbounded knapsack
    int val1 = func(fib , i , count , val , sum + fib[i] , taken+1 , dp);
    if(val1!=INT_MIN)
        val1 = val1 + fib[i];
    int val2=INT_MIN;
    if(i>0)
        val2 = func(fib , i-1 , count , val , sum , taken , dp);
    return dp[i][taken]=max(val1 , val2);
}
int Solution::fibsum(int num) {
    // find the diff fib numbers
    // find fibonacci numbers
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(2);
    for(int i=2;i<num;i++ ){
        if(fib[i-1] + fib[i-2] > num)
            break;
        else
            fib.push_back(fib[i-1] + fib[i-2]);
    }
    int sz=fib.size();
    vector<vector<int>> dp(sz+5 , vector<int>(sz+5 , -1));
    int count=INT_MAX;
    func(fib, sz-1, count, num, 0, 0, dp);
    return count;
}
