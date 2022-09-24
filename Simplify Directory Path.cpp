string Solution::simplifyPath(string s) {
    string ans="";
    int n=s.size();
    stack<string> stk;
    int i=0;
    while(i<n){
        
        // Moving for all '/'
        while(i<n && s[i]=='/')
            i++;

        int c=0;
        // checking for '.'
        while(i<n && s[i]=='.'){
            i++;
            c++;
        }
        
        // if, ".." then pop
        if(c==2 && !stk.empty())
            stk.pop();
        
        // no '.' found
        if(c==0){
            string t="";
            // get the directory between / /
            while(i<n && s[i]!='/'){
                t.push_back(s[i]);
                i++;
            }
            if(t!="")
                stk.push(t);
        }
    }

    // Push all in a string
    while(!stk.empty()){
        string p = stk.top();
        reverse(p.begin() , p.end());
        p.push_back('/');
        ans.append(p); // appending the string at end
        stk.pop();
    }
    
    if(ans=="")
        ans.push_back('/');
    reverse(ans.begin() , ans.end());
    return ans;
}
