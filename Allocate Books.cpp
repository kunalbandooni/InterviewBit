bool valid(vector<int> &A,int n,int mid,int b){
    int cnt=0,sum=0;
    for(int i=0;i<n;i++){
        if(sum+A[i]<=mid)
            sum+=A[i];
        else{
            cnt++;
            sum=0;
            sum+=A[i];
        }
    }
    return cnt<b;
}
int Solution::books(vector<int> &A, int B) {  
    int n=A.size();
    if(n<B)
        return -1;
    int maxi=A[0],sum=0;
    for(int i=0;i<n;i++){
        maxi=max(maxi,A[i]);
        sum+=A[i];
    }
   
    int low=maxi,high=sum,ans;
   
    while(low<=high){
        int mid=(low+high)/2;
        if(valid(A,n,mid,B)){
            ans=mid;
            high=mid-1;
        }
        else
            low=mid+1;
    }
    return ans;
}
