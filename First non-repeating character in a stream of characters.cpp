string Solution::solve(string A) {
    int n=A.length();
    unordered_map<char, int> mp;
    queue<char> q;
    string ans;
    
    for(int i=0; i<n; i++){
        mp[A[i]]++;
        q.push(A[i]);

        while(!q.empty() and mp[q.front()] > 1)
            q.pop();

        if(q.empty())
            ans.push_back('#');
        else
            ans.push_back(q.front());
    }
    return ans;
}
