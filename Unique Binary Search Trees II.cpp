/*
This can be also done using Catalan Number Formula

Series of numbers you will get after solving is called
The Catalan series, and a lot of question are asked
based on simply calculation of Nth catalan number. 

Read more at:
_ https://www.geeksforgeeks.org/applications-of-catalan-numbers _
*/


int Solution::numTrees(int A) {
    int dp[A+1] = {0};
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=A; i++)
        for(int j=0; j<i; j++)
            dp[i] += dp[j]*dp[i-j-1];
    return dp[A];
}
