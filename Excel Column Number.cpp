int Solution::titleToNumber(string A) {
    int s=0;
    int j=0;
    for(int i=A.length()-1;i>=0;i--)
        s=(s*26)+(A[j++]-'A'+1);
    return s;
}
