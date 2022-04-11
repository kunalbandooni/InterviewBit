string Solution::convertToTitle(int A) {
    string s="";
    while(A){
        s += ((A-1)%26 + 'A');
        A--;    
        A = A / 26;
    }
    reverse(s.begin(), s.end());
    return s;
}
