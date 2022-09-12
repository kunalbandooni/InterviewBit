int Solution::findMedian(vector<vector<int> > &A) {
    int r=A.size();
    int c=A[0].size();
    int k = (r * c + 1) / 2;
    int a = INT_MAX;
    int b = INT_MIN;
    for(int i = 0; i < r; i++){
        a = min(a, A[i][0]);
        b = max(b, A[i][c-1]);
    }
    while(a < b){
        int m = (a + b) / 2;
        int count = 0;
        for(int i = 0; i < r; i++)
            count = count + upper_bound(A[i].begin(), A[i].end(), m) - A[i].begin();
        if(count < k) a = m + 1;
        else b = m;
    }
    return a;
}
