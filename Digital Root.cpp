int order(int n){
    int a=0;
    while(n){
        n=n/10;
        a++;
    }
    return a;
}
int Solution::solve(int A) {
    int sum=0;
    do{
        sum=0;
        while(A){
            sum+=(A%10);
            A=A/10;
        }
        A=sum;
    }while(order(sum)!=1);
    return A;
}
