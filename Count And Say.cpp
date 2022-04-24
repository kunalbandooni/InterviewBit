string Solution::countAndSay(int n) {
    if(n==1)
        return "1";
    if(n==2)
        return "11";
    string res="11";
    for(int i=3;i<=n;i++){
        string t="";
        res = res + '&';    // for ending
        int count = 1;
        for(int j=1;j<res.size();j++){
            if(res[j] != res[j-1]){
                t = t + to_string(count);
                t = t + res[j-1];
                count = 1;
            }
            else
                count++;
        }
        res = t;
    }
    return res;
}
