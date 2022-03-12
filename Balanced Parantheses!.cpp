int Solution::solve(string a) {
    stack<char> s;
    if(a[0]!='(')
        return 0;
    s.push(a[0]);
    for(int i=1;i<a.length();i++){
        if(a[i]=='('){
            s.push(a[i]);
            continue;
        }
        if(s.empty())
            return 0;
        if(s.top()=='(' and a[i]==')')
            s.pop();
        else
            return 0;
    }
    if(!s.empty())     
        return 0;
    return 1;
}
