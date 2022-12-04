int Solution::solve(vector<int> &A){
    unordered_map<int,int> um;
    int sum=0;
    for(int i=0;i<A.size();i++){
        if(A[i]==0)
            sum=sum-1;
        else
            sum=sum+1;
        um[sum]=i;
    }
    int max1 = INT_MIN;
    sum = 0;
    int p = um[1]+1;
    max1 = max(max1,p);
    for(int i=0;i<A.size();i++){
        if(A[i]==0)
            sum=sum-1;
        else
            sum=sum+1;
        int t=um[sum+1];
        int z=t-i;
        max1=max(max1,z);
    }
    return max1;
}
