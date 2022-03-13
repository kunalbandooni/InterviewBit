string Solution::serialize(vector<string> &A) {
    string s="";
    for(int i=0;i<A.size();i++){
        int c=A[i].length();
        s=s+A[i];
        s=s+to_string(c);
        s=s+'~';
    }
    return s;
}
