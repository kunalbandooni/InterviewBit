long long gcd(long long int a, long long int b){
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
long long lcm(int a, int b){
    return (a / gcd(a, b)) * b;
}
long Solution::solve(int A, int B) {
    long long y=A*B;
    long long z=(lcm(A,B));
    return z;
}
