// Sum of multiples of a upto N
long calculate_sum(int a, int N){
    // Number of multiples
    long m = N / a;
 
    // sum of first m natural numbers
    long sum = m * (m + 1) / 2;
 
    // sum of multiples
    long ans = a * sum;
 
    return ans;
}

long Solution::solve(int A, int B) {
    long long sum = 0;
    
    sum = calculate_sum(7,B);

    sum -= calculate_sum(7,A);

    // much needed
    if(A%7==0)
        sum += A;

    return sum;
}
