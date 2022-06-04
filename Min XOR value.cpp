int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int min = INT_MAX;
    int val;
    for(int i=0;i<A.size()-1;i++){
        val=A[i]^A[i+1];
        if(val<min)
            min=val;
    }
    return min;
}
