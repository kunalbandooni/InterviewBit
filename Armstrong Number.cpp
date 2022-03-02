int order(int N){
    int r = 0;
    while (N) {
        r++;
        N = N / 10;
    }
    return r;
}
int Solution::solve(int N) {
    int D = order(N);
    int temp = N, sum = 0;
    while (temp) {
        int Ni = temp % 10;
        sum += pow(Ni, D);
        temp = temp / 10;
    }
    if (sum == N)
        return 1;
    return 0;
}
