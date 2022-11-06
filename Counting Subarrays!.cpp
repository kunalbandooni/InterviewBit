int Solution::solve(vector<int> &A, int B) {
    int i=0, j=0, ans=0, sum=0;
    int n=A.size();
    for(int i=0;i<n;i++){   
        while(j<n and sum+A[j]<B){
            sum=sum+A[j];
            j++;
        }
        ans=ans+j-i;
        sum=sum-A[i];
    }
    return ans;
}
