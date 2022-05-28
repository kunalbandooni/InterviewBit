int Solution::solve(vector<int> &A, int B) {
    B=abs(B);
    int N=A.size();
    if(N==1) return 0;
    sort(A.begin(),A.end());
    // We are doing A[j] - A[i]. So if diff < B we must inc A[j]. So j++
    //And if diff > B we should i ++
    //Takes care of both cases : B +ve and -ve
    int i = 0, j = 1, diff = 0;
    while(i <= N && j <=N){
        diff = A[j] - A[i];
        if(i != j && diff == B) return 1;
        else if(diff < B) j++;
        else i++;
    }
    return 0;
}
