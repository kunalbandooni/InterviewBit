string Solution::addBinary(string A, string B) {
    string res;
    int i = A.length()-1, j = B.length()-1;
    int carry = 0;
    while(i >= 0 || j >= 0){ 
    //sum = carry+A[i]+B[i]
    //if sum is odd (1,3) eg. 1+1+1=11-> LSD is 1 and carry is 1. 
    //If even 1+1=10-> LSD is 0 and Carry 1
        int sum = carry;
        if(i >= 0) sum+= A[i--] - '0'; 
        if(j >= 0) sum+= B[j--] - '0'; 
        //A[i] is a character whose value is '0' or '1'.
        // We can do arithmetic operations on chars just like int.
        // So, '0' - '0' = 0, and '1' - '0' = 1.
        // Here we want to convert '0' to 0 and '1' to 1.
        // Note: ASCII value of  '0' = 48, ASCII value of '1' = 49.
        carry = (sum > 1)? 1:0;
        res+= to_string(sum%2); //sum is either 0,1,2,3
    }
    if(carry) res+='1';
    reverse(res.begin(), res.end());
    return res;
}
