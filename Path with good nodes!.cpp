void dfs(int i, int c, vector<int> adj[], vector<int> &vis, vector<int> &A, int &ans){
    if(A[i-1]==1) c--;
    vis[i]=1;
    if(adj[i].size()==1){
        if(c>=0) ans++;;
        return;
    }
   
    for(auto node : adj[i]){
        if(vis[node]==0){
            dfs(node, c, adj, vis, A, ans);
        }
    }
   
}
int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int N=A.size();
    vector<int> adj[N+1];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    vector<int> vis(N+1,0);
    int ans=0;
    dfs(1, C, adj, vis, A, ans);
    return ans;
}
