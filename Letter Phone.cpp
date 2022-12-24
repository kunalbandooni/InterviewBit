void solve(string &A, int idx, string output, vector<string> &res, vector<string> &mapping){
    if(idx >= A.length()){
        res.push_back(output);
        return;
    }
    
    int digit = A[idx] - '0';
    string s = mapping[digit];
    for(auto i : s){
        output.push_back(i);
        solve(A, idx+1, output, res, mapping);
        output.pop_back();
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> mapping {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;
    solve(A, 0, "", res, mapping);
    return res;
}
