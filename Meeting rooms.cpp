int Solution::solve(vector<vector<int> > &A) {
    vector<int> st, et;
    for(int i=0;i<A.size();i++){
        st.push_back(A[i][0]);
        et.push_back(A[i][1]);
    }
    
    sort(st.begin(), st.end());
    sort(et.begin(), et.end());
    int ans=1;
    int count=1;
    int i=1,j=0,n=st.size();
    while(i<n && j<n){
        if(st[i]<et[j]){
            count++;
            i++;
        }
        else {
            count--;
            j++;
        }
        ans=max(ans,count);
    }
    return ans;
}
