#include<list>
void dfs(int node,unordered_map<int,list<int>> &adjList,unordered_map<int,bool> &visited){
    visited[node] = 1;
    for(auto i:adjList[node])
        if(!visited[i])
            dfs(i,adjList,visited);
}
int Solution::breakRecords(int A, vector<vector<int> > &B) {
    unordered_map<int,list<int>> adjList;
    unordered_map<int,bool> visited;
    for(int i=0; i<B.size(); i++){
        int u = B[i][0];
        int v = B[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    int count = 0;
    for(int i=1; i<=A; i++){
        if(!visited[i]){
            count++;
            dfs(i,adjList,visited);
        }
    } 
    return count;
}
