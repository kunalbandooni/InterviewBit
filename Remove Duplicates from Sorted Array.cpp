int Solution::removeDuplicates(vector<int> &A) {
    int c = 1, j = 1;
    for(int i=1;i<A.size();i++)
        if(A[i]!=A[i-1]){
            A[j] = A[i];
            c++;
            j++;
        }
    return c;
}
