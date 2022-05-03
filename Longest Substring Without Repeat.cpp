int Solution::lengthOfLongestSubstring(string A) {
    // https://www.code-recipe.com/post/longest-substring-without-repeating-characters
    unordered_map<char,int> m;
    int n=A.length(),ans=1,l=0;
    for(int i=0;i<n;i++){
        if(m.find(A[i])!=m.end() && m[A[i]]>=l){ 
            ans=max(ans,i-l);
            l=m[A[i]]+1;
        }
        m[A[i]]=i;
    }
    ans=max(ans,n-l);
    return ans;
}
