string Solution::solve(string A) {
    vector<int> arr(26,0);
    queue<char> c;
    for(auto i: A){
        if(arr[i-'a']==0)
            c.push(i);
        arr[i-'a']++;
    }
    string ans="";
    while(!c.empty())
        ans+=c.front()+to_string(arr[c.front()-'a']),c.pop();
    return ans;
}
