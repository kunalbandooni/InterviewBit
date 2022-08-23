int Solution::checkPath(vector<vector<int>> &A) {
    pair<int,int> src;
    pair<int,int> des;
   
    int n = A.size();
   
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(A[i][j]==1) src = {i,j};
            if(A[i][j]==2) des = {i,j};
        }
   
    queue<pair<int,int>> q;
   
    vector<vector<int>> av(n,vector<int>(n));
    q.push(src);
   
    while(!q.empty()){
        pair<int,int> curr = q.front();
        q.pop();
       
        int i = curr.first;
        int j = curr.second;
       
        if(curr==des) return 1;
       
        av[i][j]=1;
       
        int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
       
        for(int t=0;t<4;t++){
            int x = i+dir[t][0];
            int y = j+dir[t][1];
           
            if(x==n||y==n||x==-1||y==-1||av[x][y]||!A[x][y]) continue;
           
            av[x][y]=1;
           
            q.push({x,y});
        }        
    }
    return 0;
}
