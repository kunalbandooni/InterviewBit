int Solution::solve(string A){
    int n = A.length();
    if(n == 1)
        return 0;
    int count = 0;
    int cons = 0, vowel = 0;
    for(int i=0;i<n;i++){
        if(A[i]=='a' || A[i]=='e' || A[i]=='i' || A[i]=='o' || A[i]=='u'){
            vowel++;
            count += cons;
        }
        else{
            cons++;
            count += vowel;
        }
        count = count % 1000000007;
    }
    return count;
}
