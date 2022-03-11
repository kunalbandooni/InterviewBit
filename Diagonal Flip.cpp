vector<vector<int> > Solution::solve(vector<vector<int> > &a) {
    vector<vector<int>> v;
    int n=a.size();
    for(int i=0;i<n;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            temp.push_back(a[j][i]);
        }
        v.push_back(temp);
    }
    return v;
}
