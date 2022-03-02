int Solution::numSetBits(unsigned int A) {
    // built in function :)
    // return __builtin_popcount(A);
    
    int count=0;
    while(n!=0){
        // Advanced - faster
        n=n & (n-1);
        count++;
/*
        // Basic
        if(A%2)
            count++;
        A=A/2;
*/
    }
    return count;
}
