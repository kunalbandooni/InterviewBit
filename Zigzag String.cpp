string Solution::convert(string A, int B) {
    if(s.length()<=2 || numRows==1) return s;
    int j=0,k=0;
    string res="";
    vector<string> v;
    for(int i=0; i<numRows; i++)  v.push_back("");
    int len=2*numRows-2;
    for(int i=0; i<s.length(); i++){
        int curr= i%len;
        if(curr<numRows) v[curr].push_back(s[i]);
        else {
            int curr1=v.size()- (curr+2)%numRows;
            v[curr1].push_back(s[i]);
        }
    }
    for(int i=0; i<numRows; i++) res+=v[i];
    return res;
}
