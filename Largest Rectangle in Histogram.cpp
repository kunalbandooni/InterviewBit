int Solution::largestRectangleArea(vector<int> &A) {
    int n = A.size();
    
    int leftSmall[n], rightSmall[n];
    stack<int> st;
    
    // Left Smaller Elements
    for(int i=0;i<n;i++){
        while(!st.empty() and A[st.top()] >= A[i])
            st.pop();

        if(st.empty())
            leftSmall[i] = 0;
        else
            leftSmall[i] = st.top() + 1;

        st.push(i);
    }
    
    // Empty the stack...
    while(!st.empty())
        st.pop();
    
    // Right Smaller Elements
    for(int i=n-1;i >= 0;i--){
        while(!st.empty() and A[st.top()] >= A[i])
            st.pop();

        if(st.empty())
            rightSmall[i] = n-1;
        else
            rightSmall[i] = st.top() - 1;

        st.push(i);
    }
    
    // Finding Nemo... 
    // Solution*
    
    int ans = 0;
    for(int i=0;i<n;i++){
        int area = A[i] * (rightSmall[i] - leftSmall[i] +1);
        ans = max(ans, area);
    }
    return ans;
}
