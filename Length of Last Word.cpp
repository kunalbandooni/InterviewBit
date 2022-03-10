int Solution::lengthOfLastWord(const string A) {
    int j=A.length()-1;
    int c=0;
    bool word=false;
    while(j>=0){
        if((A[j]>='a' and A[j]<='z') or (A[j]>='A' and A[j]<='Z')){
            word=true;
            c++;
        }
        else if(word and A[j]==' ')
            return c;
        j--;
    }
    if(!word)
        return 0;
    return c;
}
