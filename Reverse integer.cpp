int Solution::reverse(int A) {
    if(A==0)
        return 0;
    bool sign=false;
    if(A<0){
        sign=true;
        A=-A;
    }
    long int sum=0;
    while(A){
        if((sum*10 + (A%10)) >INT_MAX or (sum*10 + (A%10)) <INT_MIN)
            return 0;
        sum=sum*10 + (A%10);
        A=A/10;
    }
    if(sign)
        sum=-sum;
    return sum;
}
