bool isPalindrome(string s){
    int n = s.length();
    for(int i=0;i<n/2;i++)
        if(s[i] != s[n-i-1])
            return false;
    return true;
}
int Solution::solve(string A) {
    int c = 0;
    string s = "";
    int n = A.length();
    for(int i=0;i<n;i++){
        if(A[i] == ' '){
            if(isPalindrome(s))
                c++;
            s = "";
        }
        else
            s += A[i];
    }
    if(isPalindrome(s))
        c++;
    return c;
}
