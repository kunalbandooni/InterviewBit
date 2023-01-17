int factorial(int n){
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1)%1000003;
}
long long int power(long long int A,long long int B){
    int MOD=1000003;
    if(A==0) return 0;
    if(B==0) return 1;
    long result;
    if(B%2==0){
        result=power(A,B/2);
        result=(result*result)%MOD;
    }
    else{
        result=A%MOD;
        result=(result%MOD * power(A,B-1)%MOD)%MOD;
    }
    return result%MOD;
}
int Solution::findRank(string A){
    int MOD=1000003;
    int count=1;
    for(int i=0;i<A.size()-1;i++){
        int c=0;
        for(int j=i+1;j<A.length();j++){
            if(A[i]>A[j]) c++;
        }
        map<char,int>m;
        for(int j=i;j<A.size();j++)
            m[A[j]]++;
        long long d=1;
        for(auto y:m){
            d=((d%MOD)*(factorial(y.second)%MOD))%MOD;
        }
        int k=factorial(A.size()-i-1)%1000003;
        count= ( count + c * ( k * power(d,MOD-2)%MOD )%MOD ) %MOD;
    }
    return count;
}
