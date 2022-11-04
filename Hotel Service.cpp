#define pp pair<int , int>
vector<int> Solution::nearestHotel(vector<vector<int> > &grid, vector<vector<int> > &mat) {
    int m=grid.size();
    int n=grid[0].size();
   
    // apply BFS here
    queue< pp > q;
   
    vector<vector<int>> ans(m , vector<int>(n , 0) );
   
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                grid[i][j]=-1;
                q.push({i,j});
               
            }
        }
    }
   
    int dx[4]={1 , -1 , 0 , 0};
    int dy[4]={0 , 0 , 1 , -1};
   
    int d=0;
   
    while(!q.empty()){
        int sz=q.size();
        while(sz--){
            pp x=q.front();
            q.pop();
            int i=x.first;
            int j=x.second;
           
            ans[i][j]=d;
           
            for(int k=0;k<4;k++){
                int newi=i+dx[k];
                int newj=j+dy[k];
               
                if(newi>=0 && newj>=0 && newi<m && newj<n && grid[newi][newj]!=-1 ){
                    q.push({newi , newj});
                    grid[newi][newj]=-1;// visited
                }
            }
        }
        d++;
    }
    vector<int> res;
    for(int i=0;i<mat.size();i++)
        res.push_back(ans[mat[i][0]-1][mat[i][1]-1]);
    return res;    
}
