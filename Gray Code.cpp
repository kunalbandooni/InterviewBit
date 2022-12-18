vector<int> Solution::grayCode(int A) {
    if(A==1){
        vector<int> v;
        v.push_back(0);
        v.push_back(1);
        return v;
    }

    vector<int> res = grayCode(A-1);
    vector<int> v;

    for(int i=0;i<res.size();i++)
        v.push_back(0 + res[i]);

    for(int i=res.size()-1;i>=0;i--)
        v.push_back(res.size() + res[i]);

    return v;
}
