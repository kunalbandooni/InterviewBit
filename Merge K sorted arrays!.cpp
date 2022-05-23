vector<int> Solution::solve(vector<vector<int> > &A) {
    priority_queue<int, vector<int>, greater<int>> p;
    for(int i = 0; i<A.size(); i++)
        for(int j = 0; j<A[i].size(); j++)
            p.push(A[i][j]);
    
    vector<int> res;
    while(!p.empty()){
        res.push_back(p.top());
        p.pop();
    }
    
    return res;
}
