bool isPalindrome(string s){
    int l = 0, r = s.size() - 1;
    while(l<r){
        if(s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}
string addOne(string s){
    int n = s.size();
    int carry = 1;
    for(int i = n-1;i>=0;i--){
        if(carry == 0) break;
        int diff = (s[i] - 48 + carry);
        s[i] = (char)('0' + diff%10);
        carry = diff/10;
    }
    if(carry) s = '1'+s;
    return s;
}
string Solution::solve(string A) {
    string ini = A;
    if(isPalindrome(A))
        A = addOne(A);
    int n = A.size();
    int l,r;
    if(n%2 == 0){
        l = n/2 - 1;
        r = n/2;
    }
    else{
        l = n/2 - 1;
        r = n/2 + 1;
    }
    while(l>= 0 && r < n){
        A[r] = A[l];
        r++;
        l--;
    }
    if(A.size() > ini.size() || A > ini) return A;
    // cout<<"Gone for retest "<<A<<'\n';
    if(n%2){
        l = n/2;
        r = n/2;
    }
    else{
        l = n/2 - 1;
        r = n/2;
    }
    int carry = 1;
    while(carry){        
            int num = A[l] - 48 + carry;
            if(l == r){
                A[l] = (char)(num%10 + '0');
                carry = num/10;
            }
            else{
                A[l] = (char)(num%10 + '0');
                A[r] = A[l];
                carry = num/10;
            }
            l--;
            r++;
            if(l < 0 || r >= n) break;
    }
    if(carry) A = '1' + A + '1';
    return A;
}
