int dfs(int A, int node, map<int,vector<int>> & graph, vector<int> &visited){
    if(A==node)
        return 1;
    visited[node] = 1;
    int status = 0;
    for(int i=0;i<graph[node].size(); i++)
        if(visited[graph[node][i]]!=1)
            status = status || dfs(A, graph[node][i], graph, visited);
    return status;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    map<int,vector<int>> graph;
    vector<int> visited(100005,0);
    for(int i=0; i<B.size(); i++)
        graph[B[i][0]].push_back(B[i][1]);
    return dfs(A, 1, graph, visited);
}
