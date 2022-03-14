int Solution::permuteStrings(string a, string b) {
    /*
    TC: O(n . log n)    SC: O(1)
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return a==b;
    */

    // TC: O(n)    SC: O(n)
    if(a.length()!=b.length())
        return 0;
    map<char,int> m;
    for(int i=0;i<a.length();i++){
        m[a[i]]++;
        m[b[i]]--;
    }
    for(auto i:m)
        if(i.second!=0)
            return 0;
    return 1;
}
