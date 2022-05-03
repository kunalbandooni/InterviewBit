int Solution::longestConsecutive(const vector<int> &A) {
    unordered_map<int,int> m;
    int ans=1,count;
    for(int i:A){
        count=0; m[i]++;
        int j=i;
        while(m[--j]>0)
            count++;
        j=i;
        while(m[++j]>0)
            count++;
        ans=max(count+1,ans);
    }
    return ans;
}
