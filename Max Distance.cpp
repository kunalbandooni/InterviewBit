int Solution::maximumGap(const vector<int> &A) {
    vector<pair<int,int>> vec;
    for(int i=0;i<A.size();i++)
        vec.push_back({A[i],i});
    sort(vec.begin(),vec.end());
    int min_index = INT_MAX;
    int result=0;
    for(int i=0;i<A.size();i++){
        min_index=min(min_index,vec[i].second);
        result=max(result,vec[i].second-min_index);
    }
    return result;
}

/*
// BEST SOLUTION EVER:- 
// USING VINARY SEARCH
int Solution::maximumGap(const vector<int> &A) {
    int n=A.size();
    int maxi[n];
    maxi[n-1]=A[n-1];
    int ans=0;
    for(int i=n-2;i>=0;i--) maxi[i]=max(maxi[i+1],A[i]);
    for(int i=0;i<n-1;i++){
        int val=-1;
        int l=i+1,r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(maxi[mid]>=A[i]) {
                val = mid;
                l = mid+1;
            }
            else 
            r = mid-1;
        }
        if(val!=-1)
            ans=max(ans,val-i);
    }
    return ans;
}
*/
