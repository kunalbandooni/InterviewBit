bool isPrime(int a){
    for(int i=2;i*i<=a;i++)
        if(a%i==0)
            return false;
    return true;
}
vector<int> Solution::primesum(int A) {
    for(int i=2;i*i<=A;i++)
        if(isPrime(i) and isPrime(A-i))
            return {i,A-i};
}
