int Solution::solve(int A) {
    if(A%100==0){
        if(A%400==0)
            return 1;
        else    
            return 0;
    }
    else if(A%4==0)
        return 1;
    return 0;
}
