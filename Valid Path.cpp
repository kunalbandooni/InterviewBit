bool vis[101][101];
vector<int> v,z;
int r;
int dx[8]={1,0,-1,0,1,-1,-1,1};
int dy[8]={0,1,0,-1,1,-1,1,-1};
bool check(int x, int y){
    for(int i=0;i<v.size();i++)
        if(((v[i]-x)*(v[i]-x)+(z[i]-y)*(z[i]-y))<=r*r)
            return false;
    return true;
}
bool bfs(queue<pair<int,int>> q, int A, int B){
    while(!q.empty()){
        auto xx=q.front().first,yy=q.front().second;
        if(xx==A&&yy==B) 
            return true;
        vis[xx][yy]=true;
        
        for(int i=0;i<8;i++){
            int x=xx+dx[i],y=dy[i]+yy;
            if(x<=A&&y<=B&&x>=0&&y>=0&&!vis[x][y]&&check(x,y)){
                q.push({x,y});
                vis[x][y]=true;
            }   
        }
        
        q.pop();
    }   
    return false;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    queue<pair<int,int>> q;
    q.push({0,0});
    v.clear();
    z.clear();
    r=D;
    for(auto x:E) v.push_back(x);
    for(auto x:F) z.push_back(x);
    
    memset(vis,false,sizeof(vis));
    
    if(bfs(q,A,B))
        return "YES";
    return "NO";
}
