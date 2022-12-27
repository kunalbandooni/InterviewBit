bool hlpr(vector<int>&A,int h,int B){
    int cnt=0;
    for(int i=0;i<A.size();i++){
        if(A[i]>h){
            cnt+=A[i]-h;
        }
    }
    return cnt>=B;
}

int Solution::solve(vector<int> &A, int B) {
    //sort(A.begin(),A.end());
   
    int l=1;
    int h=1e6;
    int ans=0;
    while(l<=h){
        int md=l+(h-l)/2;
        if(hlpr(A,md,B)){
            ans=max(ans,md);
            l=md+1;
        }else{
            h=md-1;
        }
    }
    return ans;
}
