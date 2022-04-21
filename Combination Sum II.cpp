void MakeAns(int curr,int target,vector<int>& path, vector<vector<int> >& ans,vector<int>& A)
{
    if(curr==A.size())
    {
        if(target==0)
            ans.push_back(path);
        return;
    }
    if(target<0)
        return;
    int val = A[curr], end = curr;
    while(end<A.size() && A[end]==val)
            end++;
    int count = end - curr;
    for(int i=0;i<=count;i++)
    {
        MakeAns(end,target,path,ans,A);
        path.push_back(val);
        target-=val;
    }
    
    path.erase(path.begin()+path.size()-count-1,path.end());
    return;
}
vector<vector<int> > Solution::combinationSum(vector<int> &A, int target) {
    sort(A.begin(),A.end());
    vector<vector<int> > ans;
    vector<int> path;
    MakeAns(0,target,path,ans,A);
    return ans;
}

/*void util(vector<vector<int>> &res, vector<int> v, vector<int> &A, int T, int sum, int n){
    if(sum>T || n<0)
        return;
    if(sum==T){
        sort(v.begin(),v.end());
        if(find(res.begin(),res.end(),v)==res.end())
            res.push_back(v);
        return;
    }
    if(sum+A[n-1]<=T){
        sum+=A[n-1];
        v.push_back(A[n-1]);
        util(res,v,A,T,sum,n-1);
        v.pop_back();
        sum-=A[n-1];
        util(res,v,A,T,sum,n-1);
    }
    else
        util(res,v,A,T,sum,n-1);
    return;
}
vector<vector<int>> Solution::combinationSum(vector<int> &A, int B){
    vector<vector<int>>res;
    vector<int> v;
    util(res,v,A,B,0,A.size());
    sort(res.begin(),res.end());
    return res;
}
*/
