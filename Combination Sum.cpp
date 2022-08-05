void solve(vector<int> &A,vector<vector<int>> &sol,vector<int> curr,int B,int sum){
    if(sum>B)   return;
    if(sum==B){
        sort(curr.begin(),curr.end());
        for(auto x:sol)
            if(x==curr) 
                return;
        sol.push_back(curr);
        return;
    }
    
    for(int i=0;i<A.size();i++){
        if(sum+A[i]<=B){
            curr.push_back(A[i]);
            solve(A,sol,curr,B,sum+A[i]);
            curr.pop_back();
        }
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B){
    vector<vector<int>> sol;
    vector<int> curr;
    solve(A,sol,curr,B,0);
    sort(sol.begin(),sol.end());
    return sol;
}
