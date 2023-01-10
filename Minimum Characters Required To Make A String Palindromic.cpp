int lps(string pat){
    int M = pat.size();
    int lps[M];
    int len = 0;
    int i = 1;
    lps[0] = 0;
    while(i < M){
        if(pat[i] == pat[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!=0){
                len = lps[len-1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps[M-1];
}
int Solution::solve(string A) {
    string B = A;
    reverse(B.begin(), B.end());
    string pat = A+"$"+B;
    int len = lps(pat);
    return A.size() - len;
}
