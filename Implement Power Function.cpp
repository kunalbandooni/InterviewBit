/*
// SIMPLER SOLUTION DOWN THERE :)
#define ll long long int
int Solution::pow(int x, int n, int d) {
    if(d == 1) 
        return 0;
    if(x == 0) 
        return 0;
    ll ans = 1, y = x % d;
    
    while(n>0){
        if(n&1) 
            ans = ((ans) * y)%d;
        y = (y*y) % d;
        if(y<0) 
            y+=d;
        n=n>>1; //faster than n--
    }
    if(ans < 0)
        ans = (d - abs(ans) % d);
    return ans;
}
*/
int Solution::pow(int x, int n, int d) {
    if(n==1){
        if(x<0)
            return (x%d)+d;
        return x;
    }
    if(n==0 and x==0)
        return 0;
    if(n==0)
        return 1%d;
    long long temp = pow(x,n/2,d)%d;
    long long mul = (temp * temp)%d;
    if(mul<0)
        mul = mul + d;
    if(n%2==0)
        return mul;
    return (mul*x)%d;
}
