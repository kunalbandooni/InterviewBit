int Solution::isPower(int A) {
    if(A == 1)
        return true;
    for(int i=2; i*i<=A; i++){
        int x=A;
        while(x%i == 0)
            x = x/i;
        if(x==1)
            return true;
    }
    return false;
}
