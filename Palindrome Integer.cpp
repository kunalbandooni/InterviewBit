int Solution::isPalindrome(int A) {
    if(A<0)
        return 0;
    int sum=0;
    int t=A;
    while(t){
        sum=sum*10+(t%10);
        t=t/10;
    }
    if(sum==A)
        return 1;
    return 0;
}
