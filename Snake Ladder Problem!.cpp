int Solution::snakeLadder(vector<vector<int> > &A, vector<vector<int> > &B) {
    vector<pair<int,int>> adj[101];
    set<int> st;
    for(auto x:B)
    {
        st.insert(x[0]);
    }
    for(int i=1;i<=100;i++)
    {
        if(st.find(i)!=st.end())
        continue;
        for(int j=1;j<=6;j++)
        {
            if(i+j<=100)
            {
                adj[i].push_back(make_pair(i+j,1));
            }
        }
    }
    for(auto x:A)
    {
        adj[x[0]].push_back(make_pair(x[1],0));
    }
    for(auto x:B)
    {
        adj[x[0]].push_back(make_pair(x[1],0));
    }
    vector<int> dis(101,INT_MAX);
    dis[1]=0;
    deque<int> dq;
    dq.push_front(1);
    while(!dq.empty())
    {
        int v=dq.front();
        dq.pop_front();
        for(auto x:adj[v])
        {
            if(dis[v]+x.second<dis[x.first])
            {
                dis[x.first]=dis[v]+x.second;
                if(x.second==0)
                {
                     dq.push_front(x.first);
                }
                else
                {
                    dq.push_back(x.first);
                }
            }
        }
    }
    if(dis[100]!=INT_MAX)
    return dis[100];
    return -1;
}
