int Solution::solve(vector<int> &A) {
    int n=A.size();
    int min=-1;
    unordered_map<int, int> b;
    for(int i=n-1;i>=0;i--){
        b[A[i]] +=1;
        if(b[A[i]] > 1)
            min=A[i];
    }
    return min;
}
