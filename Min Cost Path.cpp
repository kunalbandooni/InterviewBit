// Intuition -> there is no dp , because a node or cell can be visited multiple times

// so what we have to do is , we update the distance value each time

// and also put that cost  and index into the pq , as it can afftect the

// cost of many path , it is possible that many path may

// conntains it in its way

#define vv vector<int>

int Solution::solve(int m , int n , vector<string> &grid) {
   
    // Dijkstra's Algorithm
   
    priority_queue< vv , vector<vv> , greater<vv>> pq;
   
    pq.push({0 , 0 , 0});
   
    int dx[4]={-1 , 1 , 0 , 0};
    int dy[4]={0 , 0  , -1 , 1};
   
    // UP , DOWN , LEFT , RIGHT
   
   
   
    vector<vector<int>> dist(m , vector<int>(n , INT_MAX));
   
    dist[0][0]=0;
   
    while(!pq.empty())
    {
        auto arr=pq.top();
        pq.pop();
       
        int cost=arr[0];
        int i=arr[1];
        int j=arr[2];
       
        int ind;
       
      if(grid[i][j]=='U')
      {
          ind=0;
      }
     
      if(grid[i][j]=='D')
      {
          ind=1;
      }
     
      if(grid[i][j]=='L')
      {
          ind=2;
      }
     
      if(grid[i][j]=='R')
      {
          ind=3;
      }
     
      for(int k=0;k<4;k++)
      {
          int newi=i+dx[k];
          int newj=j+dy[k];
         
          if(newi<0 || newj<0 || newi>=m || newj>=n)
          {
              continue;
          }
         
          if(k==ind && dist[newi][newj]>cost)
          {
              dist[newi][newj]=cost;
              pq.push({cost , newi , newj});
          }
          else
          if(dist[newi][newj]>1+cost)
          {
              dist[newi][newj]=cost+1;
              pq.push({cost+1 , newi , newj});
          }
      }
       
    }
   
    return dist[m-1][n-1];
   
}
