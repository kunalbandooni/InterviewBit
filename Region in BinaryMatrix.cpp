void dfs(vector<vector<int> > &A,vector<vector<bool>>&vis,int x[],int y[],int i,int j,int &c,int &ans,int n,int m)
{
   
    vis[i][j]=true;
    c++;
    ans=max(ans,c);
    for(int k=0;k<8;k++)
    {
        int px=i+x[k];
        int py=j+y[k];
        if(px>=0&&px<n&&py>=0&&py<m&&!vis[px][py]&&A[px][py]==1)
        {
            dfs(A,vis,x,y,px,py,c,ans,n,m);
        }
    }
}
int Solution::solve(vector<vector<int> > &A) {
    int n=A.size(),m=A[0].size();
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    int x[8]={1,-1,0,0,1,1,-1,-1};
    int y[8]={0,0,1,-1,1,-1,1,-1};
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(A[i][j]==1&&!vis[i][j])
            {
                int c=0;
                dfs(A,vis,x,y,i,j,c,ans,n,m);
            }
        }
    }
    return ans;
}
