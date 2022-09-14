bool comp(string a, string b){
    return a+b > b+a;
}
string Solution::largestNumber(const vector<int> &A) {
    vector<string> sol;
    for(int i=0;i<A.size();i++)
        sol.push_back(to_string(A[i]));
        
    sort(sol.begin(), sol.end(), comp);
    
    string ans="";
    for(auto i:sol)
        ans += i;
    if(sol[0] == "0")
        return "0";
    return ans;
}
