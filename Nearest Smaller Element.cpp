vector<int> Solution::prevSmaller(vector<int> &arr) {
    int n=arr.size();
    stack<int>st;
    vector<int>leftSmall(n);

    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()>=arr[i])
            st.pop();
        
        if(st.empty())
            leftSmall[i]=-1;
        else
            leftSmall[i]=st.top();
        
        st.push(arr[i]);
    }
    return leftSmall;
}
