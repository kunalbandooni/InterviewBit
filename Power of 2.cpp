int Solution::power(string A) {
    int last = A[A.length()-1] - '0';
    if (last%2 == 1)
        return 0;
    string B = "2";
    while(1){
        if(B.size()>A.size()) 
            break;

        if(B==A) 
            return 1;

        string C = "";
        int n = B.size();
        int carry = 0;
        for(int j=n-1;j>=0;j--){
            int x = (B[j]-'0')*2;
            x+=carry;
            C.push_back('0'+(x%10));
            carry = x/10;
        }
        while(carry>0){
            C.push_back('0'+carry%10);
            carry/=10;
        }
        reverse(C.begin(), C.end());
        B = C;
    }
    return 0;
}
