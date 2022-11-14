void visit(vector<string> &A,vector<vector<bool>> &visited, int i, int j, int &n, int &m){
    if(i < 0 || j < 0 || i >= n || j >= m) return;
    if(A[i][j] == 'O' || visited[i][j]) return;
   
    visited[i][j] = true;
   
    visit(A,visited,i+1,j,n,m);
    visit(A,visited,i,j+1,n,m);
    visit(A,visited,i-1,j,n,m);
    visit(A,visited,i,j-1,n,m);
}
int Solution::black(vector<string> &A){
    int n=A.size();
    int m=A[0].length();
   
    vector<vector<bool>> visited(n,vector<bool>(m));
    int ct=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(!visited[i][j] && A[i][j]=='X'){
                visit(A,visited,i,j,n,m);
                ct++;
            }
    return ct;
}
