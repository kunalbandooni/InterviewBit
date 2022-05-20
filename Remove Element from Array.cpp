int Solution::removeElement(vector<int> &A, int B) {
    int i=-1;
    int n = A.size();
    for(int j=0;j<n;j++)
        if(A[j]!=B){
            i++;
            swap(A[i], A[j]);
        }
    return i+1;
}
