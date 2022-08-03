// Do DFS until you visit all vertices, 
//      or until you detect a cycle
bool isCyclicDFS(int node, int parent, vector<bool> &visited, unordered_map<int, vector<int>> &adj){
    visited[node]=true;
    for(auto neighbour: adj[node]){
        if(!visited[neighbour]){
            bool cycleDetection = isCyclicDFS(neighbour,node,visited,adj);
            if(cycleDetection)
                return 1;
        }
        else if(neighbour!=parent)
            return 1;
    }
    return 0;
}
int Solution::solve(int A, vector<vector<int> > &B) {
    // vector leke ptani kya dikkat aayi =(
    unordered_map<int, vector<int>> adj;
    for(int i=0;i<B.size();i++){
        int u=B[i][0];
        int v=B[i][1];
       
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
   
    vector<bool> visited(A+1, false);
   
  // Real logic is this
    for(int i=1;i<=A;i++){
        if(!visited[i]){
            bool ans = isCyclicDFS(i,-1,visited,adj);
            if(ans == 1)  return 1;
        }
    }
    return 0;
}
