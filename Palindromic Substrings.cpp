bool isPalindrome(string s,int i,int j){
    while(i<j){
        if(s[i]!=s[j])
            return false;
        i++,j--;
    }
    return true;
}
int Solution::solve(string s) {
    int n=s.length();
    int dp[n];
   
    dp[0]=1;
   
    for(int i=1;i<n;i++){
        int count=0;
        for(int j=0;j<=i;j++){
            if(isPalindrome(s,j,i))
            count++;
        }
        dp[i]=dp[i-1]+count;
    }
    return dp[n-1];    
}
