int sum(int a,int total,vector<int> &A,vector<bool> &visited,vector<int> adj[],long long int &ans){
    visited[a]=true;
    long long int temp = A[a-1];
    for(auto x : adj[a])
        if(!visited[x])
            temp+=sum(x,total,A,visited,adj,ans);

    long long int x = temp*(total-temp);
    if(x>ans)
        ans=x;

    return temp;
}
int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    int n = A.size();
    vector<int> adj[n+1];
    for(int i=0;i<B.size();i++){
        adj[B[i][0]].push_back(B[i][1]);
        adj[B[i][1]].push_back(B[i][0]);
    }
    int total=0;
    for(auto x : A) 
        total+=x;
    vector<bool> visited(n+1,false);
    long long int ans = INT_MIN;
    sum(1,total,A,visited,adj,ans);
    return ans%(int(1e9+7));
}
