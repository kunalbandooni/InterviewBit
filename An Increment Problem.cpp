vector<int> Solution::solve(vector<int> &A) {
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>>m;
    int n=A.size();
    for(int i=0;i<n;i++){
        if(m.find(A[i])==m.end()){
            m[A[i]].push(i);
        }
        else{
            int idx=m[A[i]].top();
            m[A[i]].pop();
            A[idx]++;
            m[A[idx]].push(idx);
            m[A[i]].push(i);
        }
    }
    return A;
}
