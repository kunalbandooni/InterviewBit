bool ispalin(string &s ){
    int l=0 , r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r])
            return false;
        l++;
        r--;
    }
    return true;
}
void func(int i , string &s , vector<string> &ans , vector<vector<string>> &res , int n  ){
    if(i>=n){
        res.push_back(ans);
        return ;
    }
    for(int len =1 ; len<=n-i;len++ ){
        int j=i+len-1;
        string str=s.substr(i , len);
        if(ispalin(str)){
            ans.push_back(str);
            func(i+len , s , ans , res , n );
            ans.pop_back();
        }
    }
}
vector<vector<string> > Solution::partition(string s) {
    vector<vector<string>> res;
    vector<string> ans;
    int n=s.size();
    func(0 , s , ans , res , n);
    return res;
}
