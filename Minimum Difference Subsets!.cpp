int dp[100][5001];
int util(vector<int> &arr, int i, int target){
    if(target<=0 || i<0)
        return target;
    if(dp[i][int(target)]!=-1)
        return dp[i][int(target)];
    
    return dp[i][int(target)] = max(util(arr, i-1, target), util(arr, i-1, target-arr[i]));
}
int Solution::solve(vector<int> &arr) {
    if(arr.size()==1)
        return arr[0];
    int sum=0;
    for(int i=0; i<arr.size(); i++)
        sum+=arr[i];
    return sum&1 ? 2 * abs(util(arr, arr.size()-1, sum/2)) + 1 : 2*abs(util(arr, arr.size()-1, sum/2));
}
