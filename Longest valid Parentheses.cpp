int Solution::longestValidParentheses(string s) {
    stack<int> st;
    int n=s.size();
    int ans=0;
    vector<int> dist(n,0);
        
    for(int i=0;i<n;i++){
        if(s[i]=='(')
            st.push(i);
        else if(!st.empty()){
            int len=i-st.top()+1;
            st.pop();
            dist[i]=len;
            if(i-len>0)
                dist[i]+=dist[i-len];
            ans=max(ans,dist[i]);
        }
    }
        
    return ans;
}
