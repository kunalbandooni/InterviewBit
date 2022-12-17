const int N = 1e5+4;
vector<pair<int,int>> graph[N];
int par[32][N];
int mx[32][N];
int n;
int depth[N];
void dfs(int node, int p, int h){
    par[0][node] = p;
    depth[node] = h;
    for(auto [to, wt] : graph[node]){
        if(to == p) continue;
        mx[0][to] = wt;
        dfs(to, node, h+1);
    }
}
int get(int a, int b){
    if(a == b)
        return 0;

    if(depth[a] > depth[b]) 
        swap(a, b);

    int gap = depth[b] - depth[a];

    int ans = 0;
    for(int bit = 0; bit<32; bit++){
        if((1<<bit) & gap){
            ans = max(ans, mx[bit][b]);
            b = par[bit][b];
        }
    }

    if(a == b)  // if a and b become equal no need to lift further just return ans
        return ans;

    for(int i = 31; i>=0; i--){
        if(par[i][a] == par[i][b]) continue;
        ans = max({ans, mx[i][a], mx[i][b]});
        a = par[i][a];
        b = par[i][b];
    }
    // here they will be unequal just need lift of 1. So here we are considering that edge too.
    ans = max({ans, mx[0][a], mx[0][b]});
    return ans;
}
vector<int> Solution::solve(vector<vector<int> > &edges, vector<vector<int> > &q) {
    n = edges.size()+1;
    memset(par, -1, sizeof(par));
    memset(mx, 0, sizeof(mx));

    for(int i = 0; i<N; i++) 
        graph[i].clear(), depth[i] = 0;
    for(int i = 0; i<edges.size(); i++){
        graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    dfs(1, -1, 0);
    for(int b = 1; b<32; b++){
        for(int node = 1; node <= n; node++){
            int p = par[b-1][node];
            if(p != -1){
                par[b][node] = par[b-1][p];
                mx[b][node] = max(mx[b-1][node], mx[b-1][p]);
            }
        }
    }

    vector<int> ans;

    for(int i = 0; i<q.size(); i++){
        int a = q[i][0], b = q[i][1];
        ans.push_back(get(a, b));
    }
    return ans;
}
