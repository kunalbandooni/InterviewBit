int Solution::solve(string A) {
    int c = 0;
    char s[10]={'A','E','I','O','U','a','e','i','o','u'};
    for(int i=0;i<A.length();i++){
        for(int j=0;j<10;j++)
            if(A[i] == s[j])
                c = c + ((A.length() - i))%10003;
    }
    return c%10003;
}
