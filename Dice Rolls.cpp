int func(int A, vector<int> a){
    if(A == 0)  return 1;
    //if(a[A] != -1)  return a[A];
    int res = 0;
    for(int j = 1;j <= 6;j++)
        if(A>=j)
            res = res + func(A-j, a);
    return res;
}
int Solution::solve(int A){
    /*vector<int> a(A, -1);
    return func(A, a);*/
    int a[A+1];
    memset(a, 0, sizeof(a));
    a[0] = 1;
    int M = 1000000007;
    for(int i = 1; i< A+1 ; i++)
        for(int j = 1; j <= 6 ; j++){
           if(i >= j)  
            a[i] = (a[i] % M + a[i-j] % M) % M;
        }
    return a[A];
}
