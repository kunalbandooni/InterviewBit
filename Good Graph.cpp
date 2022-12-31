int  dfs(int node , vector<int>&adj ,  vector<int>&A , vector<bool>&visited){
   
    if(adj[node] == 1){
        visited[node] = true;
        return 0;
    }
    if(visited[node]){
        adj[node] = 1;
        return 1;
    }
    // if(node!=1 && adj[node]!=1){
    //     counts++;
    //     adj[node] == 1;
    // }
    visited[node]=true;
    //for(auto it : adj[node]){
       int res =  dfs(adj[node] , adj , A , visited);
    //}
    adj[node] = 1;
    return res;
}

int Solution::solve(vector<int> &A) {
    int n =  A.size();
    int cnt = 0;
    vector<bool> visited(n+1,false);
    vector<int> adj(n+1);
    for(int i = 1 ; i <= n ; i++){
        adj[i] =  A[i-1];
    }
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            if(dfs(i , adj ,A , visited)){
                cnt++;
            }
        }
    }
    return cnt;
}
