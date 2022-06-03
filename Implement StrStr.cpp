vector<int> build_lps(string s){
    int n = s.length();
    vector<int> lps(n);
    lps[0] = 0;
    int i = 1, len = 0;
    while(i < n){
        if(s[i] == s[len]){
            lps[i] = len + 1;
            i++;
            len++;
        }
        else{
            if(len == 0){
                lps[i] = 0;
                i++;
            }
            else
                len = lps[len - 1];
        }
    }
    return lps;
}
int Solution::strStr(const string text, const string pat) {
    int n = text.length(), m = pat.length();
    vector<int> lps = build_lps(pat);
    int i = 0, len = 0;// len is the length of pattern which is matching with the text
    while(i < n){
        if(text[i]== pat[len]){  // if same then increase the len 
            i++; 
            len++;
        }
        if(len == m)// if complete pattern matches return the starting index of patttern in text
            return (i - len);
        else if(i < n && text[i] != pat[len]){
            if(len == 0)
                i++;
            else
                len = lps[len-1];/* if not same then decrease the len to repeating part */
        }
    }
    return -1;
}
