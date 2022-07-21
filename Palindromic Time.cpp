int Solution::solve(string A) {
    int ans = 0;
    int hr = (A[0]-'0')*10 + (A[1]-'0') ;
    int min = (A[3]-'0')*10 + (A[4]-'0') ;

    while(true){
        if(hr/10==min%10 && min/10==hr%10)break;
        min++;
        ans++;
        if(min%60==0)hr++;min=min%60;
        if(hr%24==0)hr=hr%24;
    }
    return ans;

}
