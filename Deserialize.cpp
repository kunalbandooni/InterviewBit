vector<string> Solution::deserialize(string A) {
    vector<string> v;
    string s="";
    for(int i=0;i<A.length();i++){
        if(A[i]>='a' and A[i]<='z')
            s=s+A[i];
        else{
            if(!(s == ""))
                v.push_back(s);
            s="";
        }
    }
    return v;
}
