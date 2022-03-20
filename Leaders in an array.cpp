vector<int> Solution::solve(vector<int> &A) {
    // Space Complexity : O(1)
    vector<int> ans;
    int mx=0;
    for(int i=A.size()-1; i>=0; i--)
        if(A[i] > mx){
            mx = A[i];
            ans.push_back(mx);
        }
    return ans;

    // Space Complexity : O(n)
    /*
    stack<int> s;
    int i=A.size()-1;
    s.push(A[i]);
    i--;
    while(i>=0){
        if(s.top() < A[i])
            s.push(A[i]);
        i--;
    }
    vector<int> v;
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
    return v;
    */
}
