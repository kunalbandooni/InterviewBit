vector<int> Solution::solve(int A, int B, int C, int D) {
    priority_queue<int,vector<int> , greater<int>> q;
    q.push(A) ;
    if(B != A)
        q.push(B) ;
    if(C != A && C != B)
        q.push(C);
    unordered_map<int,int> m;
    m[A]++;
    m[B]++;
    m[C]++;
    vector<int> ans;
    while(ans.size() < D){
        int val = q.top();
        q.pop();
        ans.push_back(val);
        if(m.find(val*A) == m.end()){
            q.push(val*A);
            m[val*A]++;
        }
        if(m.find(val*B) == m.end()){
            q.push(val*B);
            m[val*B]++;
        }
        if(m.find(val*C) == m.end()){
            q.push(val*C);
            m[val*C]++;
        }
    }
    return ans;
}
