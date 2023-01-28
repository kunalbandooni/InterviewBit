int Solution::solve(string s, string target, vector<string> &d) {
    // BFS
    set< string > st;
    for(auto x : d)
        st.insert(x);
   
    queue<string> q;
    q.push(s);
    int ans=1;
    while(!q.empty())
    {
        int sz=q.size();
        while(sz--)
        {
            string str=q.front();
            q.pop();
           
            if(str==target)
                return ans;
           
            for(int i=0;i<str.size();i++)
            {
                string s1=str;
                char ch=s1[i];
               
                for(int j=0;j<26;j++)
                {
                    s1[i]='a'+ j;
                   
                    if(s1 != str && st.find(s1)!=st.end())
                    {
                        q.push(s1);
                        st.erase(s1); // after inseeting that string in queue
                        // make sure that same string is not inserted again
                        // again so , delete from dictionary set
                    }
                }
            }
        }
        ans++;
    }
    return 0;
}
