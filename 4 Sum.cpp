vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    int n=A.size();

    map<int,vector<pair<int,int>>> mm;
    set<vector<int>> ans;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(mm.find(B-(A[i]+A[j]))!=mm.end()){           
                for(auto ele: mm[B-A[i]-A[j]]){
                    vector<int> temp={ele.first,ele.second,A[i],A[j]};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }
            }       
        }
        for(int y=0;y<i;y++)
            mm[A[y]+A[i]].push_back({A[y],A[i]});
    }
    vector<vector<int>> v;
    for(auto i: ans)
        v.push_back(i);
    return v;
}
