void Solution::arrange(vector<int> &A) {
    int n=A.size();
    for(int i=0;i<n;i++){
        int x=A[i];
        int y=A[x];
        A[i]=x+(y%n)*n;
    }
    for(int i=0;i<n;i++)
        A[i] = A[i]/n;
}
