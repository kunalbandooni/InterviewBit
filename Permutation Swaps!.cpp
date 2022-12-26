const int N=1e6;
int parent[N];
int siz[N];
void make (int &v){
    parent[v]=v;
    siz[v]=1;
}
int find(int &v){
    if(parent[v]==v)
        return v;
    return parent[v]=find(parent[v]);
}
void join(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)    return ;
    if(siz[b]>siz[a])
        swap(a,b);
    parent[b]=a;
    siz[a]+=siz[b];
}
int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    int n=A.size();
    unordered_map <int,int> mp;
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++)
    {
        mp[B[i]]=i;
        make(i);
        if(A[i]==B[i])
            vis[i]=true;
    }
    //vector<int> g[n];
    for(auto &x:C)
        join(x[0]-1,x[1]-1);
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            int id=mp[A[i]];
            if(id==-1)
                return 0;
            if(find(id)==find(i)){
                vis[i]=true;
                vis[id]=true;
            }
            else
                return 0;
        }
    }
    return 1;
}
