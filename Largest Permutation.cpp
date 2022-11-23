vector<int> Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    vector<int> temp=A;
    sort(temp.begin(),temp.end());
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++) 
        mp[A[i]]=i;
    int i=0;
    while(i<n && B){
        int idx=mp[temp[n-1-i]];
        if(A[i]!=A[idx]){
            swap(A[i],A[idx]);
            mp[A[idx]]=idx;
            B--;
        }
        i++;
    }
    return A;
}
