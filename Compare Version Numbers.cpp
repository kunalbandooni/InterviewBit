int move(int i, int n, string &s){
    while(i < n && s[i] == '0')
        i++;
    return i;
}

int Solution::compareVersion(string version1, string version2) 
{
    int n = version1.length(), m = version2.length();
    int i = 0, j = 0;
    while(i < n || j < m){
        
        i = move(i , n, version1);
        j = move(j, m, version2);
        string s1, s2;
        while(i < n && version1[i] != '.'){
            s1 += version1[i];
            i++;
        }

        while(j < m && version2[j] != '.'){
            s2 += version2[j];
            j++;
        }

        if(s1.length() > s2.length())
            return 1;
        else if(s1.length() < s2.length())
            return -1;
        else{
        if(s1 < s2) 
            return -1;
        else if(s1 > s2)
            return 1;
        }
        i++;
        j++;
    }
    return 0;
}
