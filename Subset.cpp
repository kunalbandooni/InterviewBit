void generate(vector<int> &A,int index,vector<int> &ans,vector<vector<int>> &subs)
{
 subs.push_back(ans);  
    for(int i=index; i<A.size();i++)
    {
        ans.push_back(A[i]);
        generate(A,i+1,ans,subs);
        ans.pop_back();//backtraking
    }
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<int> ans;
    vector<vector<int>> subs;
    sort(A.begin(),A.end());
    generate(A,0,ans,subs);
    return subs;
}
