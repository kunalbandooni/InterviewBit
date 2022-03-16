int Solution::solve(int A) {
    int i=1,j=1,count=0;
    for(i=1;i<=A;i++)
        for(j=i;j<=A;j++){
            int a = i*i;
            int b =j*j;
            int c = a+b;
            int x = sqrt(c);
            if( x*x == c and x <= A)
                count++;
        }   
    return count;
}
