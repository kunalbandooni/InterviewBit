bool dfs(int node, vector <vector <int>> &adj, vector <int> &color){
    if(color[node] == -1)
        color[node] = 1;
   
    for(auto child: adj[node]){
        if(color[child] == -1){
            color[child] = 1 - color[node];
            if(!dfs(child, adj, color))
                return false;
        } 
        else if(color[child] == color[node])
            return false;
    }
    return true;
}

int Solution::solve(int n, vector<vector<int> > &b) {
    int m = b.size();
    vector <vector <int>> adj(n);
    vector <int> color(n, -1);
   
    for(int i = 0; i < m; i++){
        int u = b[i][0] - 1;
        int v = b[i][1] - 1;
       
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    for(int i = 0; i < n; i++)
        if(color[i] == -1)
            if(!dfs(i, adj, color))
                return false;
    return true;
}
