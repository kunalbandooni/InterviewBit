void solve(string &op, int open, int close, vector<string>&ans){
    if(open==0 && close ==0 ){
        ans.push_back(op);
        return;
    }

    if(open > 0){
        op.push_back('(');
        solve(op,open-1,close,ans);
        op.pop_back();
    }

    if(close > 0){
        if( close > open){
            op.push_back(')');
            solve(op,open,close-1,ans);
            op.pop_back();
        }
    }
}
vector<string> Solution::generateParenthesis(int n) {
    string op;
    vector<string> ans;
    solve(op,n,n,ans);
    return ans;
}
