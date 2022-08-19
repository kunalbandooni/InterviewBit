#include<bits/stdc++.h>

void createAdjacencyList(unordered_map<int,list<int>> &adjList,int &u,int &v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void bfsUtil(unordered_map<int,list<int>> &adjList, unordered_map<int,bool> &visited,int node){
    visited[node] = 1;
    queue<int> q;
    q.push(node);
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}

int bfs(unordered_map<int,list<int>> &adjList, unordered_map<int,bool> &visited,int nodes){
    int count = 0;
    for(int i=1; i<=nodes; i++){
        if(!visited[i]){
            count++;
            bfsUtil(adjList,visited,i);
        }
    }
    return count;
}


int Solution::solve(int A, vector<vector<int>> &B) {
    unordered_map<int,list<int>> adjList;
    unordered_map<int,bool> visited;
   
    for(int i=0; i<B.size(); i++){
        int u = B[i][0];
        int v = B[i][1];
        createAdjacencyList(adjList,u,v);
    }
    int result = bfs(adjList,visited,A);
    return result;
}
